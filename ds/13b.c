#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int *arr;
    int size;
    int count;
};

void initqueue(struct Queue* q, int n){
    q->size = n;
    q->count = 0;
    q->arr = (int*)malloc(n * sizeof(int));
}

int isFull(struct Queue* q){
    return q->count == q->size;
}

int isEmpty(struct Queue* q){
    return q->count == 0;
}

void enqueue(struct Queue* q, int val){
    if(isFull(q)){
        printf("Queue Overflow\n");
        return;
    }

    int i = q->count - 1;
    while(i >= 0 && q->arr[i] > val){
        q->arr[i + 1] = q->arr[i];
        i--;
    }
    q->arr[i + 1] = val;
    q->count++;
}

void dequeue(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted: %d\n", q->arr[0]);
    for(int i = 0; i < q->count - 1; i++)
        q->arr[i] = q->arr[i + 1];
    q->count--;
}

void display(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue Empty\n");
        return;
    }
    for(int i = 0; i < q->count; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

int main(){
    struct Queue q;
    int n, ch, val;

    printf("Enter queue size: ");
    scanf("%d", &n);
    initqueue(&q, n);

    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1: scanf("%d", &val); enqueue(&q, val); break;
            case 2: dequeue(&q); break;
            case 3: display(&q); break;
            case 4: exit(0);
        }
    }
}
