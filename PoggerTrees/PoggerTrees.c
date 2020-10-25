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

// Best Case: O(1)
// Worse Case: O(n)
// Average Case: O(1)
int treeDiff(node *a, node *b)
{
    // Base Case
    if (a == NULL && b == NULL)
        return 0;

    if (a == NULL ^ b == NULL || a->data != b->data)
        return 1;

    return treeDiff(a->left, b->left) || treeDiff(a->right, b->right);
}

// Best Case: O(n)
// Worst Case: O(n)
// Average Case: O(n)
int countOneChild(node *root)
{
    // Base Case
    if (root == NULL)
        return 0;

    return ((root->left == NULL && root->right != NULL) ||
            (root->right == NULL && root->left != NULL)) +
           (countOneChild(root->left) + countOneChild(root->right));
}

// Best Case: O(1)
// Worst Case: O(n)
// Average Case: O(log n)
node *largest(node *root)
{
    if (root->right == NULL)
        return root;

    return largest(root->right);
}

// Best Case: O(n)
// Worst Case: O(n)
// Average Case: O(n)
int countNodes(node *root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Best Case: O(n)
// Worst Case: O(n)
// Average Case: O(n)
int countLeafNodes(node *root)
{
    if (root == NULL)
        return 0;

    return (root->right == NULL && root->left == NULL) +
           countLeafNodes(root->left) +
           countLeafNodes(root->right);
}

// Best Case: O(n)
// Worst Case: O(n)
// Average Case: O(n)
int countGreater(node *root, int key)
{
    if (root == NULL)
        return 0;

    return (root->data > key) +
           countGreater(root->left, key) +
           countGreater(root->right, key);
}

// Best Case: O(1)
// Worse Case: O(n)
// Average Case: O(log n)
int BST_countGreater(node *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->data <= key)
        return BST_countGreater(root->right, key);
    else
        return 1 + BST_countGreater(root->right, key) + BST_countGreater(root->left, key);
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
        root = bstInsert(root, num);
    }
    inorder(root);
    printf("%d\n", BST_countGreater(root, 80));

    return 0;
}