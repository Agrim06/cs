#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct LL{
    struct Node* head;
    int size;
};

struct Node* createnode(int val){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void initlist(struct LL* list){
    list->head = createnode(0);
    list->head->next = NULL;
    list->size = 0;
}

void display(struct LL* list){
    struct Node* temp = list->head->next;
    if(temp == NULL){
        printf("List Empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertfront(struct LL* list, int val){
    struct Node* temp = createnode(val);
    temp->next = list->head->next;
    list->head->next = temp;
    list->size++;
    display(list);
}

void insertatpos(struct LL* list, int val, int pos){
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
    p->next = temp;
    list->size++;

    display(list);
}

void deletebykey(struct LL* list, int key){
    struct Node* p = list->head;

    while(p->next != NULL && p->next->data != key)
        p = p->next;

    if(p->next == NULL){
        printf("Key Not Found\n");
        display(list);
        return;
    }

    struct Node* temp = p->next;
    p->next = temp->next;
    free(temp);
    list->size--;

    display(list);
}

void searchbypos(struct LL* list, int pos){
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
    struct LL list;
    int ch, val, pos;

    initlist(&list);

    while(1){
        printf("\n1.Insert Front\n2.Insert at Position\n3.Delete by Key\n4.Search by Position\n5.Display\n6.Exit\n");
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
