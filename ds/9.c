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
    list->head->next = NULL;      
    list->size = 0;
}


void display(struct CSLL* list){
    if(list->head->next == NULL){
        printf("List Empty\n");
        return;
    }

    struct Node* temp = list->head->next;

    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while(temp != list->head->next);

    printf("START\n");
}


void insertordered(struct CSLL* list, int val){
    struct Node* temp = createnode(val);

    if(list->head->next == NULL){
        list->head->next = temp;
        temp->next = temp;
    }
    else{
        struct Node* p = list->head->next;
        struct Node* prev = NULL;

        do{
            if(p->data >= val)
                break;
            prev = p;
            p = p->next;
        }while(p != list->head->next);

        if(prev == NULL){
     
            struct Node* last = list->head->next;
            while(last->next != list->head->next)
                last = last->next;

            temp->next = list->head->next;
            list->head->next = temp;
            last->next = temp;
        }
        else{
            prev->next = temp;
            temp->next = p;
        }
    }
    list->size++;
    display(list);
}


void deleterear(struct CSLL* list){
    if(list->head->next == NULL){
        printf("List Empty\n");
        return;
    }

    struct Node* first = list->head->next;

    if(first->next == first){
        free(first);
        list->head->next = NULL;
    }
    else{
        struct Node* prev = NULL;
        struct Node* curr = first;

        while(curr->next != first){
            prev = curr;
            curr = curr->next;
        }
        prev->next = first;
        free(curr);
    }
    list->size--;
    display(list);
}


void deletefront(struct CSLL* list){
    if(list->head->next == NULL){
        printf("List Empty\n");
        return;
    }

    struct Node* first = list->head->next;

    if(first->next == first){
        free(first);
        list->head->next = NULL;
    }
    else{
        struct Node* last = first;
        while(last->next != first)
            last = last->next;

        list->head->next = first->next;
        last->next = list->head->next;
        free(first);
    }
    list->size--;
    display(list);
}


void reverse(struct CSLL* list){
    if(list->head->next == NULL || list->head->next->next == list->head->next){
        display(list);
        return;
    }

    struct Node *prev = NULL, *curr = list->head->next, *next;
    struct Node* first = curr;

    do{
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }while(curr != list->head->next);

    first->next = prev;
    list->head->next = prev;

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