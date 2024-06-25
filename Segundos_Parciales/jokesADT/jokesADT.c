#include "jokesADT.h"
#include <string.h>

#define JOKES_BLOCK 10
#define STRING_BLOCK 50

typedef struct joke{
    char* jokeString;
    size_t stringSize;
} TJoke;

typedef struct category{
    struct category* tail;
    char* categoryName;
    TJoke* jokes;
    size_t jokesAmount;
} category;
typedef category* TCategory;

struct jokesCDT{
    TCategory first;
    size_t dim;
};

jokesADT newJokes(void){
    jokesADT new = calloc(1, sizeof(struct jokesCDT));
    return new;
}

static TCategory addCategoryRec(TCategory node, const char *category, char* added){
    int c;
    *added = 0;
    if(node == NULL || (c = strcmp(node->categoryName, category)) > 0){
        TCategory new = calloc(1, sizeof(*new));
        new->categoryName = (char*) category;
        new->tail = node;
        *added = 1;
        return new;
    }
    if(c == 0){
        return node;
    }
    node->tail = addCategoryRec(node->tail, category, added);
    return node;
}

void addCategory(jokesADT jokes, const char *category){
    char added = 0;
    jokes->first = addCategoryRec(jokes->first, category, &added);
    jokes->dim += added;
}

static TCategory findCategory(TCategory node, const char* category){
    int c;
    if(node == NULL || (c = strcmp(node->categoryName, category)) > 0)
        return NULL;
    if(c == 0)
        return node;
    return findCategory(node->tail, category);
}

void addJoke(jokesADT jokes, const char *category, const char *joke){
    TCategory cat = findCategory(jokes->first, category);
    if(cat == NULL){
        return ;
    }
    //Realloc de a bloques del joke
    if(cat->jokesAmount % JOKES_BLOCK == 0){
        cat->jokes = realloc(cat->jokes, sizeof(*cat->jokes) * (cat->jokesAmount + JOKES_BLOCK));
        for(int i = cat->jokesAmount; i < (cat->jokesAmount + JOKES_BLOCK); i++){
            cat->jokes[i].jokeString = NULL;
            cat->jokes[i].stringSize = 0;
        }
    }
    //Realloc de a bloques del string
    int i;
    for(i = 0; joke[i] != 0; i++){
        if(i % STRING_BLOCK == 0){
            cat->jokes[cat->jokesAmount].jokeString = realloc(cat->jokes[cat->jokesAmount].jokeString, i + STRING_BLOCK);
        }
        cat->jokes[cat->jokesAmount].jokeString[i] = joke[i];
    }
    cat->jokes[cat->jokesAmount].stringSize = i;
    cat->jokes[cat->jokesAmount].jokeString = realloc(cat->jokes[cat->jokesAmount].jokeString, cat->jokes[cat->jokesAmount].stringSize + 1);
    cat->jokes[cat->jokesAmount].jokeString[i] = 0;
    cat->jokesAmount++;
}

char * joke(jokesADT jokes, const char * category){
    TCategory cat = findCategory(jokes->first, category);
    if(cat == NULL || cat->jokesAmount == 0)
        return NULL;
    char* res = malloc(cat->jokes[0].stringSize + 1);
    strcpy(res, cat->jokes[0].jokeString);
    return res;
}

static TCategory deleteCategoryRec(TCategory node, const char* category, char* del){
    int c;
    if(node == NULL || (c = strcmp(node->categoryName, category)) > 0){
        return node;
    }
    if(c == 0){
        TCategory aux = node->tail;
        *del = 1;
        free(node);
        return aux;
    }
    node->tail = deleteCategoryRec(node->tail, category, del);
    return node;
}

void deleteCategory(jokesADT jokes, const char * category){
    char del = 0;
    jokes->first = deleteCategoryRec(jokes->first, category, &del);
    jokes->dim-=del;
}

size_t categoriesCount(const jokesADT jokes){
    return jokes->dim;
}

char ** categories(const jokesADT jokes){
    if(jokes->dim == 0){
        return NULL;
    }
    char** res = malloc(sizeof(*res) * jokes->dim);
    TCategory current = jokes->first;
    int i = 0;
    while(current != NULL){
        res[i] = malloc(strlen(current->categoryName) + 1);
        strcpy(res[i], current->categoryName);
        current = current->tail;
        i++;
    }
    return res;
}

static void freeJokesRec(TCategory node){
    if(node == NULL){
        return ;
    }
    free(node->tail);
    for(int i = 0; i < node->jokesAmount; i++){
        free(node->jokes[i].jokeString);
    }
    free(node->jokes);
}

void freeJokes(jokesADT jokes){
    freeJokesRec(jokes->first);
    free(jokes);
}
