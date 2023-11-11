#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

char isEmpty(struct Queue *Q)
{
    if (Q->front == NULL && Q->rear == NULL)
        return 1;
    else
        return 0;
}

void Enqueue(struct Queue *Q, int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = NULL;
    
    if (isEmpty(Q) == 1)
    {
        Q->front = ptr;
        Q->rear = ptr;
    }
    else
    {
        Q->rear->next = ptr;
        Q->rear = ptr;
    }
}

struct Node *Dequeue(struct Queue *Q)
{
    struct Node *temp;
    if (Q->front == Q->rear)
    {
        temp = Q->front;
        Q->front = NULL;
        Q->rear = NULL;
    }
    else
    {
        temp = Q->front;
        Q->front = Q->front->next;
    }
    return temp;
    free(temp);
}

struct Node *Front(struct Queue *Q)
{
    return Q->front;
}

void Display(struct Queue *Q)
{
    struct Node *temp;
    temp = Q->front;
    while (temp != NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
}

void main()
{
    int choice, val;
    struct Node *temp;
    struct Queue *Q;
    struct Queue queue;
    Q = &queue;
    
    while(1)
    {
        printf("\n**********MENU**********");
        printf("\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &val);
                Enqueue(Q, val);
                break;
            case 2:
                if (isEmpty(Q) == 1)
                    printf("Queue is Empty");
                else
                {
                    temp = Dequeue(Q);
                    printf("Element dequeued: %d", temp->data);
                }
                break;
            case 3:
                if (isEmpty(Q) == 1)
                    printf("Queue is Empty");
                else
                {
                    temp = Front(Q);
                    printf("Element at Front: %d", temp->data);
                }
                break;
            case 4:
                if (isEmpty(Q) == 1)
                    printf("Queue is Empty");
                else
                    Display(Q);
                break;
            case 5:
                printf("Exiting.....");
                exit(0);
            default:
                printf("Invalid choice!!!!");
                break;
        }
    }
}