#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* next;
    int data;
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

void insertordered(struct LL* list, int val){
    struct Node* temp = createnode(val);
    struct Node* p = list->head;

    while(p->next != NULL && p->next->data < val)
        p = p->next;

    temp->next = p->next;
    p->next = temp;
    list->size++;

    display(list);
}

void deletefront(struct LL* list){
    if(list->head->next == NULL){
        printf("List Empty\n");
        return;
    }

    struct Node* temp = list->head->next;
    list->head->next = temp->next;
    free(temp);
    list->size--;

    display(list);
}

void search(struct LL* list, int key){
    struct Node* p = list->head->next;
    int pos = 1;

    while(p != NULL){
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

int main(){
    struct LL list;
    int ch, val;

    initlist(&list);

    while(1){
        printf("\n1.Insert Ordered\n2.Delete Beginning\n3.Search by Key\n4.Delete by Key\n5.Display\n6.Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                scanf("%d", &val);
                insertordered(&list, val);
                break;

            case 2:
                deletefront(&list);
                break;

            case 3:
                scanf("%d", &val);
                search(&list, val);
                break;

            case 4:
                scanf("%d", &val);
                deletebykey(&list, val);
                break;

            case 5:
                display(&list);
                break;

            case 6:
                exit(0);
        }
    }
}
