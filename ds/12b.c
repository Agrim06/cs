#include<stdio.h>
#include<stdlib.h>

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
        printf("Deque Empty\n");
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

void insertfront(struct Queue* q, int val){
    if(isFull(q)){
        printf("Deque Full\n");
        return;
    }

    if(isEmpty(q)){
        q->front = q->rear = 0;
    }
    else if(q->front == 0){
        q->front = q->size - 1;
    }
    else{
        q->front--;
    }

    q->queue[q->front] = val;
    display(q);
}

void insertrear(struct Queue* q, int val){
    if(isFull(q)){
        printf("Deque Full\n");
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

void deletefront(struct Queue* q){
    if(isEmpty(q)){
        printf("Deque Empty\n");
        return;
    }

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

void deleterear(struct Queue* q){
    if(isEmpty(q)){
        printf("Deque Empty\n");
        return;
    }

    if(q->front == q->rear){
        q->front = q->rear = -1;
    }
    else if(q->rear == 0){
        q->rear = q->size - 1;
    }
    else{
        q->rear--;
    }

    display(q);
}

int main(){
    struct Queue dq;
    int n, ch, val;

    printf("Enter deque size: ");
    scanf("%d", &n);
    init(&dq, n);

    while(1){
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1: scanf("%d", &val); insertfront(&dq, val); break;
            case 2: scanf("%d", &val); insertrear(&dq, val); break;
            case 3: deletefront(&dq); break;
            case 4: deleterear(&dq); break;
            case 5: display(&dq); break;
            case 6: exit(0);
        }
    }
}
