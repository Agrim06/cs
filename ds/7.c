#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct CDLL{
    struct Node* head;
    int size;
};

struct Node* createnode(int val){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->prev = newnode->next = NULL;
    return newnode;
}

void initlist(struct CDLL* list){
    list->head = createnode(0);
    list->head->next = list->head;
    list->head->prev = list->head;
    list->size = 0;
}

void display(struct CDLL* list){
    struct Node* temp = list->head->next;

    if(temp == list->head){
        printf("List Empty\n");
        return;
    }

    while(temp != list->head){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("HEAD\n");
}

void insertfront(struct CDLL* list, int val){
    struct Node* temp = createnode(val);

    temp->next = list->head->next;
    temp->prev = list->head;
    list->head->next->prev = temp;
    list->head->next = temp;

    list->size++;
    display(list);
}

void insertatpos(struct CDLL* list, int val, int pos){
    if(pos < 1 || pos > list->size + 1){
        printf("Invalid Position\n");
        display(list);
        return;
    }

    struct Node* temp = createnode(val);
    struct Node* p = list->head;

    for(int i = 1; i < pos; i++)
        p = p->next;

    temp->next = p->next;
    temp->prev = p;
    p->next->prev = temp;
    p->next = temp;

    list->size++;
    display(list);
}

void deletebypos(struct CDLL* list, int pos){
    if(pos < 1 || pos > list->size){
        printf("Invalid Position\n");
        display(list);
        return;
    }

    struct Node* p = list->head->next;

    for(int i = 1; i < pos; i++)
        p = p->next;

    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    list->size--;

    display(list);
}

void searchbykey(struct CDLL* list, int key){
    struct Node* p = list->head->next;
    int pos = 1;

    while(p != list->head){
        if(p->data == key){
            printf("Key found at position %d\n", pos);
            display(list);
            return;
        }
        p = p->next;
        pos++;
    }

    printf("Key Not Found\n");
    display(list);
}

int main(){
    struct CDLL list;
    int ch, val, pos;

    initlist(&list);

    while(1){
        printf("\n1.Insert Front\n2.Insert at Position\n3.Delete by Position\n4.Search by Key\n5.Display\n6.Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                scanf("%d", &val);
                insertfront(&list, val);
                break;

            case 2:
                scanf("%d%d", &val, &pos);
                insertatpos(&list, val, pos);
                break;

            case 3:
                scanf("%d", &pos);
                deletebypos(&list, pos);
                break;

            case 4:
                scanf("%d", &val);
                searchbykey(&list, val);
                break;

            case 5:
                display(&list);
                break;

            case 6:
                exit(0);
        }
    }
}
