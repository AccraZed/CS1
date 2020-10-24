#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct Queue
{
    int size;
    node *head;
    node *tail;
} Queue;

node *createNode(int data)
{
    node *ret_node = malloc(sizeof(node));

    ret_node->next = NULL;
    ret_node->data = data;

    return ret_node;
}

void enqueue(Queue *q, int data)
{
    if (q->head == NULL)
    {
        q->head = q->tail = createNode(data);
        printf("Enqueuing %d...\n", data);
        (q->size)++;
        printf("size: %d\n", q->size);
        return;
    }
    
    printf("Enqueuing %d...\n", data);
    (q->size)++;
    printf("size: %d\n", q->size);
    q->tail->next = createNode(data);
    q->tail = q->tail->next;
    return;
}

int dequeue(Queue *q)
{
    node *ret_node;
    int ret_val;

    if (q->size == 0)
    {
        printf("!!!!!!\n");
        return INT_MIN;
    }

    ret_node = q->head->next;
    ret_val = q->head->data;

    free(q->head);

    printf("Dequeuing %d...\n", ret_val);
    (q->size)--;
    q->head = ret_node;
    return ret_val;
}

void printList(node *list)
{
    node *temp = list;

    while (temp != NULL)
    {
        printf("%d%c", temp->data, temp->next == NULL ? '\n' : ' ');
        temp = temp->next;
    }
}

void insertNode(node **head, int data)
{
    node *temp = *head;
    node *temp_jr;

    printf("Inserting %d...\n", data);

    if (*head == NULL)
    {
        *head = createNode(data);
        return;
    }

    if (temp->data > data)
    {
        temp_jr = temp->next;
        temp->next = createNode(temp->data);
        temp->next->next = temp_jr;
        temp->data = data;
        return;
    }

    while (temp != NULL)
    {
        if (temp->data < data && temp->next != NULL && temp->next->data >= data)
        {
            temp_jr = temp->next;
            temp->next = createNode(data);
            temp->next->next = temp_jr;
            return;
        }
        else if (temp->next == NULL)
        {
            temp->next = createNode(data);
            return;
        }
        temp = temp->next;
    }
}

void recursiveCreateNode(node **head, int data)
{
    node *temp;

    // Base Case
    if ((*head)->data >= data)
    {
        temp = (*head)->next;
        (*head)->next = createNode((*head)->data);
        (*head)->next->next = temp;
        (*head)->data = data;
        return;
    }
    // Base Case
    if ((*head)->next == NULL)
    {
        (*head)->next = createNode(data);
        return;
    }

    recursiveCreateNode(&(*head)->next,data);
    return;
}

node **merge(node **left, node **right, int range)
{
    int i = 0, index_right = 0, oob = range & 1 ? range / 2 + 1 : range / 2;
    node *cur_left = *left, *cur_right = *right;

    int *sorted = malloc(sizeof(int) * range);

    // While the left and right are still in bound
    while (cur_left != *right && index_right < oob)
    {
        if (cur_left->data < cur_right->data)
        {
            sorted[i++] = cur_left->data;
            cur_left = cur_left->next;
        }
        else
        {
            sorted[i++] = cur_right->data;
            cur_right = cur_right->next;
            index_right++;
        }
    }

    // Add the rest of the right if any
    while (index_right < oob)
    {
        sorted[i++] = cur_right->data;
        cur_right = cur_right->next;
        index_right++;
    }

    // Add the rest of the left if any
    while (cur_left != *right)
    {
        sorted[i++] = cur_left->data;
        cur_left = cur_left->next;
    }

    // Write the array onto the linked list
    cur_left = *left;
    for (i = 0; i < range; i++)
    {
        cur_left->data = sorted[i];
        cur_left = cur_left->next;
    }

    free(sorted);

    return left;
}

node **mergeSort(node **left, int range)
{
    int i, mid = range / 2;
    node *right = *left;

    if (range <= 1)
        return left;

    for (i = 0; i < mid; i++)
        right = right->next;

    mergeSort(&right, range & 1 ? mid + 1 : mid);

    mergeSort(left, mid);

    merge(left, &right, range);

    return left;
}

int main(void)
{
    node *head = NULL, *cur;
    Queue *q = calloc(1, sizeof(Queue));
    int i, val = 0;

    srand(time(NULL));

    int max = rand() % 50 + 1;

    head = createNode(rand() % 1000 + 1);
    cur = head;

    for (i = 0; i < max; i++)
    {
        cur->next = createNode(rand() % 1000 + 1);
        cur = cur->next;
    }

    printList(head);
    mergeSort(&head, max + 1);
    printList(head);

    return 0;
}

