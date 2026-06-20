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
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = val;
	temp->next = NULL;
	return temp;
}

void initlist(struct LL *list){
	list->head = createnode(0);
	list->head->next = NULL;
	list->size = 0;
}

void display(struct LL* list){
	if(list->head->next == NULL) return;
	
	struct Node* temp = list->head->next;
	do{
		printf("%d->",temp->data);
		temp = temp->next;
	}
	while(temp != list->head->next);
	printf("END\n");
}

void insertbyorder(struct LL* list ,int val){
	struct Node* new = createnode(val);

	if(list->head->next == NULL){
		new->next = new;
		list->head->next = new;
		list->size++;
		return;
	}
	struct Node* curr = list->head->next;
	struct Node* prev = NULL;

	while(curr->next != list->head->next && curr->data < val){
		prev = curr;
		curr = curr->next;
	}

	if(prev == NULL && val < curr->data){
		struct Node* last = list->head->next;
		while(last->next != list->head->next)
			last = last->next;
			
		new->next = list->head->next;
		last->next = new;
		list->head->next = new;	
	}else{
		new->next = curr->next;
		curr->next = new;
	}
	list->size++;
}

void deleterear(struct LL* list){
	if(list->head->next == NULL) return;

	if(list->head->next->next == list->head->next){
		list->head->next =NULL;
		list->size--;
		return;
	}
	
	struct Node* last = list->head->next;
	struct Node* temp = NULL;

	while(last->next != list->head->next){
		temp = last;
		last = last->next;
	}	
	temp->next = last->next;
	free(last);
	list->size--;
}


void deletefront(struct LL *list){
	if(list->head->next == NULL) return;	

	struct Node* first = list->head->next;
	if(first->next == first){
		free(first);
		list->head->next == NULL;
		list->size--;
		return;
	}	
	
	struct Node* last = first;
	
	while(last->next != list->head->next){
		last = last->next;
	}

	list->head->next = first->next;
	last->next = first->next;
	free(first);
	list->size--;
}

void reverse(struct LL* list){
	if(list->head->next == NULL || list->head->next->next == list->head->next) return;
	
	struct Node* temp = list->head->next;
	struct Node* prev = temp;
	struct Node* first = temp;
	struct Node* front;
	while(temp->next != list->head->next){
		front = temp->next;
		temp->next = prev;
		prev = temp;
		temp = front;
	}
	temp->next = prev;
	first->next = temp;
	list->head->next = temp;
}

int main(){
	struct LL clist;
	initlist(&clist);
	
	for(;;){
		printf("==============MENU===========\n");
		printf("1.Insert By order\n2.Delete Rear\n3.Delete Front\n4.Reverse\n5.Exit\n");
		printf("Enter your choice: ");
		int choice ,val;
		scanf("%d",&choice);
		
		switch(choice){
			case 1: printf("\nEnter the value: ");
					scanf("%d",&val);
					insertbyorder(&clist, val);
					display(&clist);
					break;
			
			case 2: deleterear(&clist);
					display(&clist);
					break;
	
			case 3: deletefront(&clist);
					display(&clist);
					break;

			case 4: reverse(&clist);
					display(&clist);
					break;
			
			case 5: exit(0);break;
			
			default:printf("Invalid choice");break;
		}
	}
}
