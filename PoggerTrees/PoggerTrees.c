#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;

    struct node *left;
    struct node *right;
} node;

node *nodeCreate(int data)
{
    node *ret_node = malloc(sizeof(node));

    // Check for failed malloc goes here

    ret_node->data = data;
    ret_node->left = NULL;
    ret_node->right = NULL;

    return ret_node;
}

node *bstInsert(node *root, int data)
{
    // You'd also want to check for failed mallocs
    if (root == NULL)
        return nodeCreate(data);

    if (data < root->data)
        root->left = bstInsert(root->left, data);
    else
        root->right = bstInsert(root->right, data);
    
    return root;
}

void inorder_base(node *root)
{
    if (root == NULL)
        return;
    
    inorder_base(root->left);
    printf("%d ", root->data);
    inorder_base(root->right);
    
    return;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        printf("(empty root)\n");
        return;
    }

    inorder_base(root);
    printf("\n");
    return;
}

void preorder_base(node *root)
{
    if (root == NULL)
        return;
    
    printf("%d ", root->data);
    preorder_base(root->left);
    preorder_base(root->right);

    return;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        printf("(empty root)\n");
        return;
    }

    preorder_base(root);
    printf("\n");
    return;
}

void postorder_base(node *root)
{
    if (root == NULL)
        return;
    
    postorder_base(root->left);
    postorder_base(root->right);
    printf("%d ", root->data);

    return;
}

void postorder(node *root)
{
    if (root == NULL)
    {
        printf("(empty root)\n");
        return;
    }

    postorder_base(root);
    printf("\n");
    return;
}

node *genderReveal(node *root)
{
    if (root == NULL)
        return NULL;

    genderReveal(root->left);
    genderReveal(root->right);
    free(root);

    return NULL;
}

int main(void)
{
    int i, num;
    node *root = NULL;

    srand(time(NULL));

    for (i = 0; i < 10; i++)
    {
        num = rand() % 100 + 1;
        printf("Inserting %d...\n", num);
        root = bstInsert(root, num);
    }

    printf("inorder: ");
    inorder(root);
    printf("preorder: ");
    preorder(root);
    printf("postorder: ");
    postorder(root);

    root = genderReveal(root);
    inorder(root);
    return 0;
}