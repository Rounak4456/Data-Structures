#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root;

struct Node *CreateTree(struct Node *root)
{
    root = NULL;
    return root;
}

struct Node *InsertElement(struct Node *root, int val)
{
    struct Node *ptr, *nodeptr, *parentptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (root == NULL)
        root = ptr;
    else
    {
        parentptr = NULL;
        nodeptr = root;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if (val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return root;
}

struct Node* InsertRecursion(struct Node* root, int data) 
{
    if (root == NULL) 
        return createNode(data);

    if (data < root->data) 
    {
        root->left = insert(root->left, data);
    } 
    else if (data > root->data) 
    {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node *smallest(struct Node *root)
{
    if(root == NULL ||(root->left == NULL))
        return root;
    else
        return smallest(root->left);
}

struct Node *DeleteElement(struct Node* root, int val)
{
    if(root == NULL)
        return NULL;
    else if(val > root->data)
        root->right = DeleteElement(root->right, val);
    else if(val < root->data)
        root->left = DeleteElement(root->left, val);
    else
    {
        if(root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct Node *temp = smallest(root->right);
            root->data = temp->data;
            root->right = DeleteElement(root->right, temp->data);
        }
    }
    return root;
}

struct Node *Search(struct Node *root, int val)
{
    if(root==NULL)
        return NULL;
    else if(val == root->data)
        return root;
    else if(val < root->data)
        return Search(root->left, val);
    else
        return Search(root->right, val);
}

void Inorder(struct Node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("%d\t", root->data);
        Inorder(root->right);
    }
}

void Preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct Node *root)
{
    if (root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d\t", root->data);
    }
}

int main()
{
    struct Node *ptr;
    int val, option, traversal;
    root = CreateTree(root);
    while(1)
    {
        printf("\n*********OPERATIONS*********");
        printf("\n1. Insert Element");
        printf("\n2. Delete Element");
        printf("\n3. Traverse");
        printf("\n4. Exit");
        printf("\nChoose the operation to be performed: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            root = InsertElement(root, val);
            break;
        case 2:
            if (root==NULL)
                printf("Tree is Empty");
            else
            {
                printf("Enter the value to be deleted: ");
                scanf("%d", &val);
                if (Search(root, val)==NULL)
                    printf("Element is not in the Tree");
                else
                    root = DeleteElement(root, val);
            }
            break;
        case 3:
            if (root == NULL)
                printf("Tree is empty");
            else
            {
                printf("\n1. INORDER\t2. PREORDER\t3. POSTORDER");
                printf("\nEnter the choice of Traversal: ");
                scanf("%d", &traversal);
                switch(traversal)
                {
                    case 1:
                        Inorder(root);
                        break;
                    case 2:
                        Preorder(root);
                        break;
                    case 3:
                        Postorder(root);
                        break;
                }
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice!!!!!...........");
            break;
        }
    } 
    return 0;
}