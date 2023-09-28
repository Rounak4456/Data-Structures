#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct stack
{
    struct node *top;
};

char isEmpty(struct stack *s)
{
    if (s->top == NULL)
        return 1;
    else
        return 0;
}
void Push(struct stack *s, struct node *ptr)
{
    ptr->next = s->top;
    s->top = ptr;
}
void Pop(struct stack *s)
{
    struct node *temp;
    temp = s->top;
    s->top = s->top->next;
    printf("Element %d is deleted.\n", temp->data);
    free(temp);
}
struct node* Peek(struct stack *s)
{
    return s->top;
}
void Display(struct stack *s)
{
    struct node *temp;
    temp = s->top;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void main()
{
    int i=0, choice;
    struct node *ptr, *x;
    struct stack *s;
    struct stack Stack1;
    s = &Stack1;

    while (i==0)
    {
        printf("******OPERATIONS******");
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter the choice of operation to be performed: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                ptr = (struct node*)malloc(sizeof(struct node));
                printf("Enter the data to be pushed: ");
                scanf("%d", &ptr->data);
                Push(s,ptr);
            break;
            case 2:
                if(isEmpty(s)==1)
                    printf("Stack Underflow!!");
                else
                    Pop(s);
            break;
            case 3:
                x = Peek(s);
                printf("Element at top: %d\n", x->data);
            break;
            case 4:
                Display(s);
            break;
            case 5:
                i=1;
            break;
        }
    }
}