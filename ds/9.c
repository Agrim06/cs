#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct CSLL{
    struct Node* head;
    int size;
};

struct Node* createnode(int val){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void initlist(struct CSLL* list){
    list->head = createnode(0);
    list->head->next = list->head;
    list->size = 0;
}

void display(struct CSLL* list){
    struct Node* temp = list->head->next;

    if(temp == list->head){
        printf("List Empty\n");
        return;
    }

    while(temp != list->head){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("HEAD\n");
}

void insertordered(struct CSLL* list, int val){
    struct Node* temp = createnode(val);
    struct Node* p = list->head;

    while(p->next != list->head && p->next->data < val)
        p = p->next;

    temp->next = p->next;
    p->next = temp;
    list->size++;

    display(list);
}

void deleterear(struct CSLL* list){
    if(list->head->next == list->head){
        printf("List Empty\n");
        return;
    }

    struct Node* p = list->head;

    while(p->next->next != list->head)
        p = p->next;

    free(p->next);
    p->next = list->head;
    list->size--;

    display(list);
}

void deletefront(struct CSLL* list){
    if(list->head->next == list->head){
        printf("List Empty\n");
        return;
    }

    struct Node* temp = list->head->next;
    list->head->next = temp->next;
    free(temp);
    list->size--;

    display(list);
}

void reverse(struct CSLL* list){
    if(list->head->next == list->head || list->head->next->next == list->head){
        display(list);
        return;
    }

    struct Node *prev = list->head, *curr = list->head->next, *next;
    struct Node* first = curr;

    do{
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }while(curr != list->head);

    list->head->next = prev;
    first->next = list->head;

    display(list);
}

int main(){
    struct CSLL list;
    int ch, val;

    initlist(&list);

    while(1){
        printf("\n1.Insert Ordered\n2.Delete Rear\n3.Delete Front\n4.Reverse\n5.Display\n6.Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                scanf("%d", &val);
                insertordered(&list, val);
                break;

            case 2:
                deleterear(&list);
                break;

            case 3:
                deletefront(&list);
                break;

            case 4:
                reverse(&list);
                break;

            case 5:
                display(&list);
                break;

            case 6:
                exit(0);
        }
    }
}
