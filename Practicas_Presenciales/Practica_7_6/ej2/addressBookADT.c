#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
#include "addressBookADT.h"


#define BLOCK 20


typedef struct person{
    tContact contact;
    struct person* tail;
} person;
typedef person* TPerson;


typedef struct group{
    TPerson first;
    size_t groupNameSize;
    char* groupName;
    struct group* tail;
    size_t groupSize;
} group;
typedef group* TGroups;



struct addressBookCDT{
    TGroups first;
    size_t size;

    TGroups currentGroup;    // Iterador para los grupos
    TPerson currentPerson;   // Iterador para las personas/contactos

};


addressBookADT newAddressBook(void){
    addressBookADT new = calloc(1, sizeof(struct addressBookCDT));
    return new;
}


static TGroups addGroupRec(TGroups group, const char* groupName, int* added){
    int c = 0;
    if (group == NULL || (c = strcasecmp(group->groupName, groupName)) > 0){
        TGroups new = calloc(1, sizeof(*new));
        new->groupNameSize = strlen(groupName);
        new->groupName = malloc((new->groupNameSize + 1));
        strcpy(new->groupName, groupName);
        new->tail = group;
        *added = 1;
        return new;
    }

    if (c < 0){
        group->tail = addGroupRec(group->tail, groupName, added);
    }
    return group;
}

int addGroup(addressBookADT addressBook, const char* groupName){
    int added = 0;
    addressBook->first = addGroupRec(addressBook->first, groupName, &added);
    return added;
}




static TPerson addContactRec(TPerson persona, tContact contact, int* added){
    int c = 0;
    if (persona == NULL || (c = strcasecmp(persona->contact.name, contact.name)) > 0){
        TPerson newP = malloc(sizeof(*newP));
        newP->tail = persona;
        newP->contact = contact;
        *added = 1;
        return newP;
    }
    if (c == 0){
        return persona;
    }
    persona->tail = addContactRec(persona->tail, contact, added);
    return persona;
}



static void addContactGroupRec(TGroups group, const char* groupName, tContact contact, int* added){
    int c = 0;
    if (group == NULL || (c = strcasecmp(group->groupName, groupName)) > 0){
        return;
    }
    if (c == 0){
        group->first = addContactRec(group->first, contact, added);
        group->groupSize += *added;
        return;
    }
    addContactGroupRec(group->tail, groupName, contact, added);
}




int addContact(addressBookADT addressBook, const char* groupName, tContact contact){
    int added = 0;
    if (addressBook == NULL){
        return 0;
    }
    addContactGroupRec(addressBook->first, groupName, contact, &added);
    return added;
}


static void toBeginfindGroup(TGroups group, const char* groupName, TPerson currentP){
    int c = 0;
    if (group == NULL || (c = strcasecmp(group->groupName, groupName)) > 0){
        return;
    }
    if (c == 0){
        currentP = group->first;
        return;
    }
    toBeginfindGroup(group->tail, groupName, currentP);
}


void toBeginForGroup(addressBookADT addressBook, const char* groupName){
    toBeginfindGroup(addressBook->first, groupName, addressBook->currentPerson);
}


int hasNextForGroup(addressBookADT addressBook){
    return addressBook->currentPerson != NULL;
}

tContact nextForGroup(addressBookADT addressBook){
    if (!hasNextForGroup(addressBook)){
        exit(1);
    }
    tContact res = addressBook->currentPerson->contact;
    addressBook->currentPerson = addressBook->currentPerson->tail;
    return res;
}




void toBegin(addressBookADT addressBook){
    addressBook->currentGroup = addressBook->first;
}

int hasNext(addressBookADT addressBook){
    return addressBook->currentGroup != NULL;
}

char* next(addressBookADT addresBook){
    if (!hasNext(addresBook)){
        exit(1);
    }
    char* copy = malloc((addresBook->currentGroup->groupNameSize + 1) * sizeof(*copy));
    strcpy(copy, addresBook->currentGroup->groupName);
    addresBook->currentGroup = addresBook->currentGroup->tail;
    return copy;
}





