#include <stdio.h>
#include <stdlib.h>

struct circular_queue
{
    int size;
    int front;
    int rear;
    int count;
    int *arr;
};

int isFull(struct circular_queue *q)
{
    return q->size == q->count;
}

void enqueue(struct circular_queue *q, int value)
{
    if (isFull(q))
    {
        printf("\nThis queue is full.\n");
    }
    else
    {
        q->arr[q->rear] = value;
        q->rear = (q->rear + 1) % q->size;
        q->count++;
        printf("\nEnqueued item: %d", value);
    }
}

int isEmpty(struct circular_queue *q)
{
    return q->count == 0;
}

int dequeue(struct circular_queue *q)
{
    if (isEmpty(q))
    {
        printf("\nThe array is empty.\n");
    }
    else
    {
        int value = q->arr[q->front];
        q->front = (q->front + 1) % q->size;
        q->count--;
        return value;
    }
}

int main()
{
    struct circular_queue q;
    q.size = 5;
    q.front = q.rear = q.count = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1);
    enqueue(&q, 10);
    enqueue(&q, 50);

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
    enqueue(&q, 1);
    enqueue(&q, 10);
    enqueue(&q, 120);

    if (isEmpty(&q))
    {
        printf("\nThe queue is empty.\n");
    }
    return 0;
}