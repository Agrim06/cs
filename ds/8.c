#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct DLL{
    struct Node* head;
    int size;
};

struct Node* createnode(int val){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void initlist(struct DLL* list){
    list->head = createnode(0);
    list->head->next = NULL;
    list->head->prev = NULL;
    list->size = 0;
}

void display(struct DLL* list){
    struct Node* temp = list->head->next;
    if(temp == NULL){
        printf("List Empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertatpos(struct DLL* list, int val, int pos){
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

    if(p->next != NULL)
        p->next->prev = temp;

    p->next = temp;
    list->size++;

    display(list);
}

void deleterear(struct DLL* list){
    if(list->head->next == NULL){
        printf("List Empty\n");
        return;
    }

    struct Node* p = list->head->next;

    while(p->next != NULL)
        p = p->next;

    p->prev->next = NULL;
    free(p);
    list->size--;

    display(list);
}

void deleteatpos(struct DLL* list, int pos){
    if(pos < 1 || pos > list->size){
        printf("Invalid Position\n");
        display(list);
        return;
    }

    struct Node* p = list->head->next;

    for(int i = 1; i < pos; i++)
        p = p->next;

    p->prev->next = p->next;

    if(p->next != NULL)
        p->next->prev = p->prev;

    free(p);
    list->size--;

    display(list);
}

void searchbyvalue(struct DLL* list, int key){
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

int main(){
    struct DLL list;
    int ch, val, pos;

    initlist(&list);

    while(1){
        printf("\n1.Insert at Position\n2.Delete Rear\n3.Delete at Position\n4.Search by Value\n5.Display\n6.Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                scanf("%d%d", &val, &pos);
                insertatpos(&list, val, pos);
                break;

            case 2:
                deleterear(&list);
                break;

            case 3:
                scanf("%d", &pos);
                deleteatpos(&list, pos);
                break;

            case 4:
                scanf("%d", &val);
                searchbyvalue(&list, val);
                break;

            case 5:
                display(&list);
                break;

            case 6:
                exit(0);
        }
    }
}
