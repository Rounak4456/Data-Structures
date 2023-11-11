#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int max, front, rear;
    int *arr;
};

char isEmpty(struct Queue *Q)
{
    if (Q->front == -1 && Q->rear == -1)
        return 1;
    else
        return 0;
}
char isFull(struct Queue *Q)
{
    if (Q->rear == Q->max-1)
        return 1;
    else
        return 0;
}

void Enqueue(struct Queue *Q, int val)
{
    if (isEmpty(Q)==1)
    {
        Q->front = 0;
        Q->rear = 0;
        Q->arr[Q->rear] = val;
    }
    else
    {
        Q->rear++;
        Q->arr[Q->rear] = val;
    }
}

void Dequeue(struct Queue *Q)
{
    int temp;
    if (isEmpty(Q)==1)
        printf("Queue is Empty");
    else if (Q->front == Q->rear)
    {
        temp = Q->arr[Q->front];
        Q->front = -1;
        Q->rear = -1;
        printf("Element %d is deleted", temp);
    }
    else
    {
        temp = Q->arr[Q->front];
        Q->front++;
        printf("Element %d is deleted", temp);
    }
}

int Front(struct Queue *Q)
{
    return Q->arr[Q->front];
}

void Display(struct Queue *Q)
{
    int i;
    for (i=Q->front; i<=Q->rear; i++)
        printf("%d\t", Q->arr[i]);
}

void main()
{
    int choice,val;
    struct Queue *Q;
    struct Queue queue;
    Q = &queue;
    printf("Enter the size of queue: ");
    scanf("%d", &Q->max);
    Q->front = -1;
    Q->rear = -1;
    Q->arr = (int *)malloc(Q->max * sizeof(int));
    while(1)
    {
        printf("\n\nOperations to be executed: ");
        printf("\n1. Enqueue\t2. Dequeue\t3. Front\t4. Display\t5. Exit\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                if (isFull(Q)==1)
                    printf("Queue is Full!!!!");
                else
                {
                    printf("Enter the data to be Enqueued:");
                    scanf("%d", &val);
                    Enqueue(Q, val);
                }
                break;
            case 2:
                Dequeue(Q);
                break;
            case 3:
                if (isEmpty(Q)==1)
                    printf("List is empty");
                else
                {
                    val = Front(Q);
                    printf("Element at front: %d", val);
                }
                break;
            case 4:
                if (isEmpty(Q)==1)
                    printf("List is empty");
                else
                    Display(Q);
                break;
            case 5:
                printf("Exiting....");
                exit(0);
                break;
        }
    }
}