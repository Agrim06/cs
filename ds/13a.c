#include<stdio.h>
#include<stdlib.h>

struct CQueue{
    int *arr;
    int front, rear, size;
};

void initqueue(struct CQueue* q, int n){
    q->size = n;
    q->front = q->rear = -1;
    q->arr = (int*)malloc(n * sizeof(int));
}

int isEmpty(struct CQueue* q){
    return q->front == -1;
}

int isFull(struct CQueue* q){
    return ((q->rear + 1) % q->size == q->front);
}

void enqueue(struct CQueue* q, int val){
    if(isFull(q)){
        printf("Queue Overflow\n");
        return;
    }
    if(isEmpty(q))
        q->front = 0;
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = val;
}

void dequeue(struct CQueue* q){
    if(isEmpty(q)){
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted: %d\n", q->arr[q->front]);

    if(q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % q->size;
}

void display(struct CQueue* q){
    if(isEmpty(q)){
        printf("Queue Empty\n");
        return;
    }
    int i = q->front;
    while(1){
        printf("%d ", q->arr[i]);
        if(i == q->rear)
            break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main(){
    struct CQueue q;
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
