// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* next,*prev;
    int data;
};

struct LL{
    struct Node* head;
    int size;
};

struct Node* createnode(int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void initlist(struct LL* list){
    list->head = createnode(0);
    list->head->next = list->head;
    list->head->prev = list->head;
    list->size = 0;
}

void display(struct LL* list){
    if(list->head->next == list->head) {
        printf("EMPTY");
        return;
    }
    struct Node* temp = list->head->next;
    
    while(temp != list->head){
        printf("%d<->",temp->data);
        temp = temp->next;
    }
    printf("HEAD\n");
}

void insertbyorder(struct LL* list,int val){
    struct Node* new = createnode(val);
    struct Node* temp = list->head;
    
    while(temp->next != list->head && temp->next->data <val){
        temp = temp->next;
    }
    new->next = temp->next;
    new->prev = temp;
    temp->next->prev = new;
    temp->next = new;
    
    list->size++;
    display(list);
}

void deletebypos(struct LL* list, int pos){
    if(list->head->next == list->head) return;
    if(pos < 1 || pos > list->size )return;
    
    struct Node* temp = list->head->next;
    
    int c = 1;
    while(c < pos){
       temp = temp->next; 
       c++;
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("\nDeleted %d\n",temp->data);
    free(temp);
    list->size--;
    display(list);
}

void searchbypos(struct LL* list, int pos){
    if(pos < 1 || pos > list->size )return;
    
    struct Node* temp = list->head->next;
    int c =1;
    
    while(c<pos){
        temp = temp->next;
        c++;
    }
    
    printf("\nFound %d at %d\n",temp->data,pos);
}

void deletebykey(struct LL* list, int key){
     if(list->head->next == list->head) return;
     
     if(key == list->head->next->data) {
         deletebypos(list,1);
         return;
     }
     
     struct Node* temp = list->head->next;
     
     while(temp != list->head && temp->data != key){
         temp = temp->next;
     }
     
     if(temp->data == key){
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        printf("\nDeleted %d\n",temp->data);
        free(temp);
        list->size--;
        display(list); 
     }else{
         printf("Key not found \n");
         display(list); 
     }

}

int main() {
    struct LL myList;
    initlist(&myList);
    int choice, val,pos;
        printf("\n--- Double Linked List Menu ---");
        printf("\n1. Insert (Ordered)\n2. Delete by pos\n3. Delete by Key\n4. Search by pos\n5. Display\n6. Exit");
    while (1) {

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertbyorder(&myList, val);
                break;
            case 2:
                printf("Enter the postion to delete: ");
                scanf("%d",&pos);
                deletebypos(&myList,pos);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &val);
                deletebykey(&myList, val);
                break;
            case 4:
                printf("Enter position to search: ");
                scanf("%d", &pos);
                searchbypos(&myList, pos);
                break;
            case 5:
                display(&myList);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
