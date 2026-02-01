#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int *queue;
    int front, rear, size;
};

void init(struct Queue* q, int n){
    q->size = n;
    q->front = -1;
    q->rear = -1;
    q->queue = (int*)malloc(n * sizeof(int));
}

int isEmpty(struct Queue* q){
    return q->front == -1;
}

int isFull(struct Queue* q){
    return ((q->front == 0 && q->rear == q->size - 1) ||
            (q->front == q->rear + 1));
}

void display(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue Empty\n");
        return;
    }

    if(q->front <= q->rear){
        for(int i = q->front; i <= q->rear; i++)
            printf("%d ", q->queue[i]);
    }else{
        for(int i = q->front; i < q->size; i++)
            printf("%d ", q->queue[i]);
        for(int i = 0; i <= q->rear; i++)
            printf("%d ", q->queue[i]);
    }
    printf("\n");
}

void enqueue(struct Queue* q, int val){
    if(isFull(q)){
        printf("Queue Full\n");
        return;
    }

    if(isEmpty(q)){
        q->front = q->rear = 0;
    }
    else if(q->rear == q->size - 1){
        q->rear = 0;
    }
    else{
        q->rear++;
    }

    q->queue[q->rear] = val;
    display(q);
}

void dequeue(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue Empty\n");
        return;
    }

    printf("Deleted: %d\n", q->queue[q->front]);

    if(q->front == q->rear){
        q->front = q->rear = -1;
    }
    else if(q->front == q->size - 1){
        q->front = 0;
    }
    else{
        q->front++;
    }

    display(q);
}

int main(){
    struct Queue q;
    int n, ch, val;

    printf("Enter queue size: ");
    scanf("%d", &n);
    init(&q, n);

    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                scanf("%d", &val);
                enqueue(&q, val);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
