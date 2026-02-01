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
	list->head = NULL;
	list->size = 0;
}

void display(struct LL *list){
	struct Node* temp = list->head;
	if(temp == NULL){
		return;
	}	
	while(temp != NULL){
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("END\n");
}

void insertfront(struct LL *list, int val){
	struct Node* new = createnode(val);
		new->next = list->head;
		list->head = new;
		list->size++;
		display(list);
}

void insertatpos(struct LL *list, int pos , int val){
	if(pos < 1 || pos > list->size) return;
	struct Node* new = createnode(val);
	struct Node* temp = list->head;
	
	if(pos == 1){
		new->next = list->head;
		list->head = new;
		list->size++;
		display(list);
		return;
	}
	int c = 1;
	while(c < pos-1){
		temp = temp->next;
		c++;
	}
	new->next = temp->next;
	temp->next = new;
	list->size++;
	display(list);
}

void deletebykey(struct LL *list, int key){
	if(list->head == NULL) return;
	
	struct Node* temp = list->head;
	
	if(temp->data == key){
		list->head = temp->next;
		free(temp);
		list->size--;
		display(list);
		return;
	} 
	
	struct Node* mover = NULL;
	
	while(temp != NULL && temp->data != key){
		mover = temp;
		temp = temp->next;
	}
	if(temp == NULL){
		printf("Key not found\n");
		display(list);
		return;
	}
	mover->next = temp->next;
	free(temp);
	list->size--;
	display(list);
}

void searchbypos(struct LL* list, int pos){
	if(pos < 1 || pos > list->size + 1) return;
	
	struct Node* temp = list->head;
	
	if(temp == NULL) return;
	
	int c = 1;
	while(c < pos){
		temp = temp->next;
		c++;
	}
	printf("%d",temp->data);
}


int main(){
	struct LL linky;
	initlist(&linky);
	
	printf("==================MENU================\n");
	printf("1.Insert At front\n2.Insert By pos\n3.Delete by key\n4.Search by pos\n5.Display\n6.Exit\n");

	
	for(;;){
		printf("Enter your choice: \n");
		int choice,val,pos,key;
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter the value: \n");
			scanf("%d",&val);
			insertfront(&linky, val);
			break;
			case 2:printf("Enter the value and position: \n");
			scanf("%d%d",&val,&pos);
			insertatpos(&linky, pos ,val);
			break;
			case 3:printf("Enter the key to be deleted: \n");
			scanf("%d",&key);
			deletebykey(&linky,key);
			break;
			case 4:printf("Enter the position: \n");
			scanf("%d",&pos);
			searchbypos(&linky, pos);
			break;
			case 5:display(&linky);
			break;
			case 6: exit(0); break;
			default : printf("Invalid"); break;
		}
	}
	
}
