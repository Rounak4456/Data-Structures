#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct CLL {
    struct Node *head;
};

char isEmpty(struct CLL *list)
{
    if (list->head == NULL)
        return 1;
    else
        return 0;
}

void Traverse(struct CLL *list)
{
    struct Node *temp;
    temp = list->head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }while (temp != list->head);
    printf("\n");
}

void AddFront(struct CLL *list, struct Node *ptr)
{
    ptr->next = list->head;
    ptr->prev = list->head->prev;
    list->head->prev = ptr;
    ptr->prev->next = ptr;
    list->head = ptr;
}

void DeleteFront(struct CLL *list)
{
    struct Node *temp;
    temp = list->head;
    list->head = list->head->next;
    list->head->prev = temp->prev;
    temp->prev->next = list->head;
    free(temp);
}

void AddEnd(struct CLL *list, struct Node *ptr)
{
    ptr->next = list->head;
    ptr->prev = list->head->prev;
    list->head->prev = ptr;
    ptr->prev->next = ptr;
}

void DeleteEnd(struct CLL *list)
{
    struct Node *temp;
    temp = list->head->prev;
    list->head->prev = temp->prev;
    temp->prev->next = list->head;
    free(temp);
}

void AddGeneral(struct CLL *list, struct Node *ptr, int pos)
{
    struct Node *temp = list->head;
    pos--;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
        if (temp == list->head)
            break;
    }
    if (temp == list->head)
    {
        printf("Invalid Position \n");
        return;
    }
    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next->prev = ptr;
    temp->next = ptr;
}

void DeleteGeneral(struct CLL *list, int pos)
{
    struct Node *temp = list->head;
    pos--;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
        if (temp->next == list->head)
            break;
    }

    if (temp->next == list->head)
    {
        printf("Not Enough Nodes in the list \n");
        return;
    }
    else
    {
        temp->next->next->prev = temp;
        temp = temp->next;
        temp->prev->next = temp->next;
        free(temp);
    }
}

int main()
{
    int choice, pos;
    struct CLL *list;
    struct CLL LIST;
    struct Node *ptr;
    list = &LIST;
    while (1)
    {
        printf("\nOperations to be performed: \n");
        printf("1. Add in Front\t2. Delete at Front\n3. Add in End\t4. Delete at End\n5. Add General\t6. Delete General\n7. Traverse\t8. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                ptr = (struct Node *)malloc(sizeof(struct Node));
                ptr->next = ptr->prev = NULL;
                printf("Enter the data: ");
                scanf("%d", &ptr->data);
                if (isEmpty(list)==1)
                {
                    ptr->next = ptr;
                    ptr->prev = ptr;
                    list->head = ptr;
                    printf("List is Empty!!  Adding the Node in front");
                }
                else
                    AddFront(list, ptr);
                break;
            case 2:
                if (isEmpty(list) == 1)
                    printf("List is Empty!!  Node cannot be deleted");
                else if (list->head->next == list->head)
                {
                    free(list->head);
                    list->head = NULL;
                }
                else
                    DeleteFront(list);
                break;
            case 3:
                ptr = (struct Node *)malloc(sizeof(struct Node));
                ptr->next = ptr->prev = NULL;
                printf("Enter the data: ");
                scanf("%d", &ptr->data);
                if (isEmpty(list)==1)
                {
                    ptr->next = ptr;
                    ptr->prev = ptr;
                    list->head = ptr;
                    printf("List is Empty!!  Adding the Node in front");
                }
                else
                    AddEnd(list, ptr);
                break;
            case 4:
                if (isEmpty(list) == 1)
                    printf("List is Empty!!  Node cannot be deleted");
                else if (list->head->next == list->head)
                {
                    free(list->head);
                    list->head = NULL;
                }
                else
                    DeleteEnd(list);
                break;
            case 5:
                ptr = (struct Node *)malloc(sizeof(struct Node));
                ptr->next = ptr->prev = NULL;
                printf("Enter the data: ");
                scanf("%d", &ptr->data);
                printf("Enter the position at which Node is to be added: ");
                scanf("%d", &pos);
                if ((isEmpty(list)==1) && (pos == 1))
                {
                    ptr->next = ptr;
                    ptr->prev = ptr;
                    list->head = ptr;
                    printf("List is Empty!!  Adding the Node in front");
                }
                else if ((isEmpty(list)==1) && (pos != 1))
                    printf("Invalid Position");
                else if (pos == 1)
                    AddFront(list, ptr);
                else
                    AddGeneral(list, ptr, pos);
                break;
            case 6:
                if (isEmpty(list) == 1)
                    printf("List is Empty!!  Node cannot be deleted");
                else
                {
                    printf("Enter the position at which Node is to be added: ");
                    scanf("%d", &pos);
                    if (list->head->next == list->head)
                    {
                        if (pos == 1)
                            list->head = NULL;
                        else
                            printf("Invalid Position");
                    }
                    DeleteGeneral(list, pos);
                }
                break;
            case 7:
                if (isEmpty(list) == 1)
                    printf("List is Empty");
                else
                    Traverse(list);
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid Choice!!");
        }
    }
    return 0;
}