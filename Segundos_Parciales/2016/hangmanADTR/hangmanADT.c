#include "hangmanADT.h"

typedef struct node{
    char* word;
    struct node* tail;
} TNode;
typedef TNode* TList;

typedef struct levels{
    size_t wordCount;
    TList first;
} levels;

struct hangmanCDT{
    levels* levels;
    size_t maxLevel;
};

hangmanADT newHangman(unsigned int maxLevel){
    hangmanADT new = malloc(sizeof(struct hangmanCDT));
    new->maxLevel = maxLevel;
    new->levels = calloc(maxLevel, sizeof(levels));   // Hasta maxLevel inclusive
    return new;
}

static int validateLevel(unsigned int maxLevel, unsigned int level, size_t wordCount){
    if (maxLevel < level || level < 1 || wordCount == 0){
        return 0;
    }
    return 1;
}


static TList addWordsRec(TList node, char* word, int* added){
    int c;
    if (node == NULL || (c = strcmp(word, node->word)) < 0){
        TList new = malloc(sizeof(*new));
        new->tail = node;
        new->word = word;
        (*added)++;
        return new;
    }
    if (c > 0){
        node->tail = addWordsRec(node->tail, word, added);
    }
    return node;
}

int addWords(hangmanADT h, char* words[], unsigned int level){
    if (level > h->maxLevel || level < 1){
        return -1;
    }
    int added = 0;
    for (int i = 0; *(words + i) != NULL; i++){
        h->levels[level - 1].first = addWordsRec(h->levels[level - 1].first, *(words + i), &added);
    }
    h->levels[level - 1].wordCount += added;
    return added;
}

int size(const hangmanADT h, unsigned int level){
    if (!validateLevel(h->maxLevel, level, h->levels[level - 1].wordCount)){
        return 0;
    }
    return h->levels[level - 1].wordCount;
}


char* word(const hangmanADT h, unsigned int level){
    if (!validateLevel(h->maxLevel, level, h->levels[level - 1].wordCount)){
        return NULL;
    }
    return h->levels[level - 1].first->word;
}

char** words(const hangmanADT h, unsigned int level){
    if (h->maxLevel < level){
        return NULL;
    }

    char** res = malloc((h->levels[level - 1].wordCount + 1) * sizeof(*res));
    TList current = h->levels[level - 1].first;
    int i;
    for (i = 0; current != NULL; i++){
        res[i] = current->word;
        current = current->tail;
    }
    res[i] = NULL;
    return res;
}

