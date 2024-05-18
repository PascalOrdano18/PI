#include <stdio.h>
#include <stdlib.h>



typedef struct node{
    int value;
    struct node* next;
} tNode;

tNode* addBack(tNode* head, int data);
tNode* add(tNode* head);
void printList(tNode* head);
void printMenu(void);


int main(void){

    tNode* head = NULL; // comienza la lista vacia

    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        if(choice > 0 && choice < 6){

            switch (choice){
                case 1:
                    add(head);
                    break;
                case 4:
                    printList(head);
                    break;
                // case 2: 
                //     remove();
                //     break;
            }
        }
    } while(choice != 5);



    return 0;
}




tNode*  add(tNode* head){
    int data = 0;
    printf("What value would you like to add?\t");
    scanf("%d", &data);

    return addBack(head, data);
}

tNode* addBack(tNode* head, int data){
    if(data <= head->value){
        return head;
    }
    tNode* new = NULL;
    if(head == NULL){
        new = malloc(sizeof(tNode));
        new->value = data;
        new->next = NULL;
        head->next = new;
    }else{
        new = malloc(sizeof(tNode));
        new->value = data;
        new->next = head;
        head = new;
    }
    return new;
}



void printList(tNode* head){

    tNode* current = head;

    while(current != NULL){
        printf("%d\t", current->value);
        current = current->next;
    }


    return;
}



void printMenu(void){
    printf("1 -> Add a Node\n2 -> Remove a Node\n3 -> Insert a node\n4 -> Print List\n5 -> Quit\n");
}




