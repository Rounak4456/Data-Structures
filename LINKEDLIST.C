#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct sll
{
    struct node *head;
};

char isEmpty(struct sll *list)
{
    if (list->head == NULL)
        return 1;
    else
        return 0;
}

void Traverse(struct sll *list)
{
    struct node *ptr;
    ptr = list->head;
    do{
        printf("%d \t",ptr->data);
        ptr = ptr->next;
    }
    while (ptr!=NULL);
}

void AddFront(struct sll *list, struct node *ptr)
{
    ptr->next = list->head;
    list->head = ptr;
}

void DeleteFront(struct sll *list)
{
    struct node *ptr;
    ptr = list->head;
    list->head = list->head->next;
    printf("The Node %d from front is deleted", ptr->data);
    free(ptr);
}

void AddEnd(struct sll *list, struct node *ptr)
{
    struct node *temp;
    temp = list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
}

void DeleteEnd(struct sll *list)
{
    struct node *temp;
    temp = list->head;
    while (temp->next->next != NULL)
    {
    temp = temp->next;
    }
    printf("The Node %d from end is deleted",temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void AddPos(struct sll *list, struct node *ptr, int pos)
{
    struct node *temp1, *temp2;
    temp1 = list->head;
    while (temp1->next!=NULL && pos!=1)
    {
        temp1 = temp1->next;
        pos--;
    }
    if (pos > 1)
        printf("Position is greater than size of the list. \n");
    else
    {
        temp2 = temp1->next;
        temp1->next = ptr;
        ptr->next = temp2;
    }
}

void DeletePos(struct sll *list, int pos)
{
    struct node *temp1, *temp2;
    temp1 = list->head;
    while (temp1!=NULL && pos!=1)
    {
        temp1 = temp1->next;
        pos--;
    }
    if (pos > 1)
        printf("Position is greater than size of the list \n");
    else
    {
        temp2 = temp1->next->next;
        free(temp1->next);
        temp1->next = temp2;
    }
}

void main()
{
    int choice, pos;
    struct sll *LIST;
    struct sll list;
    struct node *ptr;
    LIST = &list;
    LIST->head=NULL;
    
    while(1)
    {
        printf("\nOperation to be performed: \n");
        printf("1. Add in Front 2. Delete from Front 3. Add at End 4. Delete from End 5. Add General 6. Delete General 7. Traverse 8. Exit\n");
        printf("Choose the operation to be performed: ");
        scanf("%d", &choice);
            
        switch(choice)
        {
            case 1:
                ptr = (struct node *)malloc(sizeof(struct node));
                printf("Enter the data of new node: ");
                scanf("%d", &(ptr->data));
                ptr->next = NULL;
                
                if (isEmpty(LIST)==1)
                {
                    printf("The list is empty. Adding the node in the list!!");
                    LIST->head = ptr;
                }
                else
                    AddFront(LIST, ptr);
            break;
            case 2:
                if (isEmpty(LIST)==1)
                    printf("Selected List is empty. Cannot perform the operation!");
                else
                    DeleteFront(LIST);
            break;
            case 3:
                ptr = (struct node *)malloc(sizeof(struct node));
                printf("Enter the data of new node: ");
                scanf("%d", &(ptr->data));
                ptr->next = NULL;
                
                if (isEmpty(LIST)==1)
                {
                    printf("The list is empty. Adding the node in the list!!");
                    LIST->head = ptr;
                }
                else
                    AddEnd(LIST, ptr);
            break;
            case 4:
                if (isEmpty(LIST)==1)
                    printf("Selected List is empty. Cannot perform the operation!");
                else
                    DeleteEnd(LIST);
            break;
            case 5:
                ptr = (struct node *)malloc(sizeof(struct node));
                printf("Enter the data of new node: ");
                scanf("%d", &(ptr->data));
                ptr->next = NULL;
                if (isEmpty(LIST)==1)
                {
                    printf("The list is empty. Adding the node in the list!!");
                    LIST->head = ptr;
                }
                else
                {
                    printf("Enter the position at which node is to be added: ");
                    scanf("%d", &pos);
                    pos--;
                    AddPos(LIST, ptr, pos);
                }
            break;
            case 6:
                printf("Enter the position at which node is to be deleted: ");
                scanf("%d", &pos);
                pos--;
                DeletePos(LIST, pos);
            break;
            case 7:
                if (isEmpty(LIST)==1)
                    printf("Selected List is empty");
                else
                    Traverse(LIST);
            break;
            case 8:
                printf("Exiting.....");
                exit(0);
            default:
                printf("Invalid Choice!!!!\n");
                
        }   
    }
}