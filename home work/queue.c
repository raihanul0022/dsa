#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct queue *q, int value)
{
    if (isFull(q))
    {
        printf("This queue is full.");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
    }
}

int isEmpty(struct queue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("The array is empty.");
    }
    else
    {
        q->front++;
        return q->arr[q->front];
    }
}
int main()
{
    struct queue q;
    q.size = 5;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1);
    enqueue(&q, 10);
    enqueue(&q, 120);

    if (isEmpty(&q))
    {
        printf("\nThe queue is empty.");
    }

    if (isFull(&q))
    {
        printf("\nThe queue is full.");
    }

    printf("\nDequeuing item %d", dequeue(&q));
    printf("\nDequeuing item %d", dequeue(&q));
    printf("\nDequeuing item %d", dequeue(&q));
    printf("\nDequeuing item %d", dequeue(&q));
    printf("\nDequeuing item %d", dequeue(&q));
    
    if (isEmpty(&q))
    {
        printf("\nThe queue is empty.");
    }
    return 0;
}