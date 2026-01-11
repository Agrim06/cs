#include<stdio.h>
#include<stdlib.h>

struct Deque{
    int *arr;
    int front, rear, size;
};

void initdeque(struct Deque* dq, int n){
    dq->size = n;
    dq->front = -1;
    dq->rear = 0;
    dq->arr = (int*)malloc(n * sizeof(int));
}

int isFull(struct Deque* dq){
    return ((dq->front == 0 && dq->rear == dq->size-1) ||
            (dq->front == dq->rear + 1));
}

int isEmpty(struct Deque* dq){
    return (dq->front == -1);
}

void insertfront(struct Deque* dq, int val){
    if(isFull(dq)){
        printf("Deque Overflow\n");
        return;
    }
    if(isEmpty(dq))
        dq->front = dq->rear = 0;
    else if(dq->front == 0)
        dq->front = dq->size - 1;
    else
        dq->front--;
    dq->arr[dq->front] = val;
}

void insertrear(struct Deque* dq, int val){
    if(isFull(dq)){
        printf("Deque Overflow\n");
        return;
    }
    if(isEmpty(dq))
        dq->front = dq->rear = 0;
    else if(dq->rear == dq->size - 1)
        dq->rear = 0;
    else
        dq->rear++;
    dq->arr[dq->rear] = val;
}

void deletefront(struct Deque* dq){
    if(isEmpty(dq)){
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted: %d\n", dq->arr[dq->front]);
    if(dq->front == dq->rear)
        dq->front = dq->rear = -1;
    else if(dq->front == dq->size - 1)
        dq->front = 0;
    else
        dq->front++;
}

void deleterear(struct Deque* dq){
    if(isEmpty(dq)){
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted: %d\n", dq->arr[dq->rear]);
    if(dq->front == dq->rear)
        dq->front = dq->rear = -1;
    else if(dq->rear == 0)
        dq->rear = dq->size - 1;
    else
        dq->rear--;
}

void display(struct Deque* dq){
    if(isEmpty(dq)){
        printf("Deque Empty\n");
        return;
    }
    int i = dq->front;
    while(1){
        printf("%d ", dq->arr[i]);
        if(i == dq->rear)
            break;
        i = (i + 1) % dq->size;
    }
    printf("\n");
}

int main(){
    struct Deque dq;
    int n, ch, val;

    printf("Enter deque size: ");
    scanf("%d", &n);
    initdeque(&dq, n);

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
