#include <stdio.h>
#include <stdlib.h>

int *arr;
int n=0, capacity;

void display(){
    if(n==0) {printf("Array is Empty!");
    return;
    }
    for(int i = 0 ; i < n ; i++){
        printf("%d ", arr[i]);
    }
}

void insertbyorder(){
    int val;

    if(n == capacity){
        capacity *= 2;
        arr = (int*)realloc(arr, capacity * sizeof(int));
        if(arr == NULL){
            printf("Memory allocation failed!\n");
            return;
        }
    }

    printf("Enter the value: ");
    scanf("%d", &val);

    int i = n - 1;

    while(i >= 0 && arr[i] > val){
        arr[i + 1] = arr[i];
        i--;
    }

    arr[i + 1] = val;
    n++;
}


void deletebypos(){
    int pos;
    
    if(n== 0){
        printf("Array is empty!\n");
        return;
    }
    
    printf("Enter the pos: ");
    scanf("%d",&pos);
    
    if(pos < 0 || pos > n) return;
    
    for(int i = n - 1 ; i > pos ; i--){
            arr[i - 1] = arr[i];
        }
        n--;
    }

void searchbypos(){
    int pos;
    
    if(n== 0){
        printf("Array is empty!\n");
        return;
    }
    
    printf("Enter the position to be searched: ");
    scanf("%d",&pos);
    
    if(pos < 0 || pos >= n) return;
    
    printf("Item at position %d is %d", pos,arr[pos]);
}

void reverse(){
    for(int i =0 ;i < n/2 ; i++ ){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

int main(){
    printf("\nEnter the capacity of the array: ");
    scanf("%d",&capacity);
    
    arr = (int*)malloc(capacity * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed!");
        return 0;
    }
            printf("\n=============MENU==============");
        printf("\n1.Insert by order\n2.Delete By pos\n3.Search by pos\n4.Reverse\n5.Display\n");
    for(;;){

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: insertbyorder();
                    display();
                    break;
            case 2: deletebypos();
                    display();
                    break;
            case 3: searchbypos();
                    break;
            case 4: reverse();
                    display();
                    break;
            case 5:
                    display();
                    break;
            default:printf("\nInvalid choice!");
                    break;
        }
    }
}










