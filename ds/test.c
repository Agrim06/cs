#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next, *prev;
};

struct LL{
	struct Node* head;
	int size;
};

struct Node* createnode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->next = n->prev = NULL;
    return n;
}

void initlist(struct LL* list){
	list->head = NULL;
	// list->head->next = list->head;
	// list->head->prev = list->head;
	list->size =0;
}

void insertbypos(struct LL* list, int pos , int val){
	if(pos < 1 || pos > list->size + 1) return;
	struct Node* new = createnode(val); 
	
	if(list->head == NULL){
		new->next =  new;
		new->prev = new;
		list->head = new;
		list->size++;
		return;
	}

	if(pos == 1){
		struct Node* last = list->head->prev;	
		new->next = list->head;
		new->prev = last;
		last->next= new;
		list->head->prev = new;
		list->head = new;

		list->size++;
		return;
	}

	int c = 1;
	struct Node* temp = list->head;
	while(c < pos ){
		temp = temp->next;
		c++;
	}
	
	new->next = temp;
	new->prev = temp->prev;
	temp->prev->next = new;
	temp->prev = new;
	list->size++;
}

void deleterear(struct LL* list){
	if(list->head == NULL) return;
	
	struct Node* temp= list->head;
	while(temp->next != list->head){
		temp = temp->next;
	}	
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	printf("Deleting:%d \n",temp->data);
	free(temp);
	list->size--;
}

void deleteatpos(struct LL* list , int pos){
	if(pos < 1 || pos > list->size + 1) return;
	
	struct Node* temp = list->head;

	if(pos == 1){
		if(list->size == 1){
			printf("Deleting:%d \n",temp->data);
			free(temp);
			list->head = NULL;
			list->size--;
			return;
		}

		struct Node* last = list->head->prev;
		list->head = temp->next;	
		last->next = list->head;
		list->head->prev = last;
		printf("Deleting:%d \n",temp->data);	
		free(temp);
		list->size--;
		return;
	}
	int c = 1;
	while(c<pos){
		temp = temp->next;
		c++;
	}		
	
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	printf("Deleting:%d \n",temp->data);
	free(temp);
	list->size--;
}

void display(struct LL* list){
	if(list->head == NULL) return;
	
	struct Node* temp = list->head;
	
	while(temp->next != list->head){
		printf("%d<->",temp->data);
		temp = temp->next;
	}
    printf("%d<->HEAD\n", temp->data);
}
int main(){
	struct LL dlist;
	int ch,pos,val;
	initlist(&dlist);
	
while(1){
        printf("\n1.Insert by pos\n2.Delete rear\n3.Delete by pos\n4.Display\n6.Exit\n");
		printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                scanf("%d%d",&pos, &val);
                insertbypos(&dlist,pos, val);
				display(&dlist);
                break;

            case 2:
                deleterear(&dlist);
				display(&dlist);
				break;

            case 3:
                scanf("%d", &pos);
                deleteatpos(&dlist, pos);
				display(&dlist);
				break;

            case 4:
                display(&dlist);
                break;

            case 5:
                exit(0);
        }
    }
}

