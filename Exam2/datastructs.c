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


int main(void)
{
    node *head = createNode(0), *temp = head;
    Queue *q = calloc(1, sizeof(Queue));
    int i, val = 0;

    srand(time(NULL));

    for (i = 0; i < 3; i++)
    {
        enqueue(q, i * (10) + (rand() % 10 + 1));
    }

    printList(q->head);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    printList(q->head);

    enqueue(q, 15);
    enqueue(q, 16);
    enqueue(q, 17);

    printList(q->head);

    return 0;
}

