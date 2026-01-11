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

void insertordered(struct CDLL* list, int val){
    struct Node* temp = createnode(val);
    struct Node* p = list->head->next;

    while(p != list->head && p->data < val)
        p = p->next;

    temp->next = p;
    temp->prev = p->prev;
    p->prev->next = temp;
    p->prev = temp;

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

void deletebykey(struct CDLL* list, int key){
    struct Node* p = list->head->next;

    while(p != list->head && p->data != key)
        p = p->next;

    if(p == list->head){
        printf("Key Not Found\n");
        display(list);
        return;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    list->size--;

    display(list);
}

void searchbypos(struct CDLL* list, int pos){
    if(pos < 1 || pos > list->size){
        printf("Invalid Position\n");
        display(list);
        return;
    }

    struct Node* p = list->head->next;

    for(int i = 1; i < pos; i++)
        p = p->next;

    printf("Element at position %d is %d\n", pos, p->data);
    display(list);
}

int main(){
    struct CDLL list;
    int ch, val, pos;

    initlist(&list);

    while(1){
        printf("\n1.Insert Ordered\n2.Delete by Position\n3.Delete by Key\n4.Search by Position\n5.Display\n6.Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                scanf("%d", &val);
                insertordered(&list, val);
                break;

            case 2:
                scanf("%d", &pos);
                deletebypos(&list, pos);
                break;

            case 3:
                scanf("%d", &val);
                deletebykey(&list, val);
                break;

            case 4:
                scanf("%d", &pos);
                searchbypos(&list, pos);
                break;

            case 5:
                display(&list);
                break;

            case 6:
                exit(0);
        }
    }
}
