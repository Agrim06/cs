#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct CDLL{
    struct Node *head;
    int size;
};

struct Node* createNode(int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->prev = temp->next = NULL;
    return temp;
}

void initList(struct CDLL* list){
    list->head = createNode(0);
    list->head->next = list->head;
    list->head->prev = list->head;
    list->size = 0;
}

void display(struct CDLL* list){
    if(list->head->next == list->head){
        printf("List is empty\n");
        return;
    }

    struct Node* temp = list->head->next;
    while(temp != list->head){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("HEAD\n");
}

void insertFront(struct CDLL* list, int val){
    struct Node* newnode = createNode(val);

    newnode->next = list->head->next;
    newnode->prev = list->head;
    list->head->next->prev = newnode;
    list->head->next = newnode;

    list->size++;
    display(list);
}

void insertAtPos(struct CDLL* list, int val, int pos){
    if(pos < 1 || pos > list->size + 1){
        printf("Invalid position\n");
        display(list);
        return;
    }

    struct Node* newnode = createNode(val);
    struct Node* temp = list->head;

    for(int i = 1; i < pos; i++)
        temp = temp->next;

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;

    list->size++;
    display(list);
}

void deleteByPos(struct CDLL* list, int pos){
    if(pos < 1 || pos > list->size){
        printf("Invalid position\n");
        display(list);
        return;
    }

    struct Node* temp = list->head->next;

    for(int i = 1; i < pos; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
    list->size--;

    display(list);
}

void searchByKey(struct CDLL* list, int key){
    if(list->head->next == list->head){
        printf("List is empty\n");
        return;
    }

    struct Node* temp = list->head->next;
    int pos = 1;

    while(temp != list->head){
        if(temp->data == key){
            printf("Key %d found at position %d\n", key, pos);
            display(list);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Key not found\n");
    display(list);
}

int main(){
    struct CDLL list;
    initList(&list);

    int choice, val, pos;

    while(1){
        printf("\n1.Insert Front\n2.Insert at Position\n3.Delete by Position\n4.Search by Key\n5.Display\n6.Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                scanf("%d", &val);
                insertFront(&list, val);
                break;

            case 2:
                scanf("%d%d", &val, &pos);
                insertAtPos(&list, val, pos);
                break;

            case 3:
                scanf("%d", &pos);
                deleteByPos(&list, pos);
                break;

            case 4:
                scanf("%d", &val);
                searchByKey(&list, val);
                break;

            case 5:
                display(&list);
                break;

            case 6:
                exit(0);
        }
    }
}
