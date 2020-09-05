#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

// The node that houses data
typedef struct Node
{
    char *name;
    struct Node *next;
} Node;

// The list that points to the first node in the list
typedef struct NodeBase
{
    Node *first;
} NodeBase;

/*
names       0x105
+---------------+
| first: 0x245  |
+---------------+

p           0x151
+---------------+
| name: data    |
+---------------+
| next: NULL    |
+---------------+

q           0x173
+---------------+
| name: data    |
+---------------+
| next: 0x151   |
+---------------+

r           0x245
+---------------+
| name: data    |
+---------------+
| next: 0x173   |
+---------------+
*/

void initList(NodeBase *list)
{
    list -> first = NULL;
}

void push(NodeBase *list, char *data)
{
    Node *p = malloc(sizeof(Node));
    p -> name = malloc(sizeof(char) * (strlen(data) + 1));
    strcpy(p -> name, data);
    p -> next = list -> first;
    list -> first = p;

    // printf("%s added to the list:\nAt: \t%p\nNext: \t%p\nls at: \t%p\n\n",p -> name, p, p -> next, list -> first);
}

// Get rid of the first node in a list
void pop(NodeBase *list)
{
    if (list -> first != NULL)
    {
        Node *p = list -> first;
        free(p -> name);
        list -> first = list -> first -> next;
        free(p);
    }
    else
    {
        printf("No more nodes to pop!\n");
    }
}

// Return the name located at the nth node in the list
char *getNth(NodeBase *list, int index)
{
    int i;
    Node *cur_node = NULL;

    if (list -> first != NULL)
    {
        cur_node = list -> first; 

        for (i = 0; i < index; i++)
        {
            cur_node = cur_node -> next;
        }
        return cur_node -> name;
    }
    else
    {
        printf("Can't call getNth. List's ->first is null!\n");
        return "!";
    }
}

// Print all the names in a list
void printAll(NodeBase *list)
{
    Node *cur_node = NULL;
    int cur_index;

    if (list -> first != NULL)
    {
        cur_node = list -> first; 
        cur_index = 1;

        while (cur_node != NULL)
        {
            printf("Person %d: %s\n", cur_index, cur_node -> name);
            cur_node = cur_node -> next;
            cur_index++;
        }
    }
    else
    {
        printf("Can't printAll. List's ->first is null!\n");
    }
}

int main(void)
{
    FILE *ifp;
    int i = 0;
    NodeBase ls_name;

    char buffer[1000];

    // Open names file
    if ((ifp = fopen("names.txt","r")) == NULL)
    {
        printf("Error: File \"%s\" not found.\n", "names.txt");
    }
    else
    {
        printf("File \"%s\" found!\n", "names.txt");
    }

    // Initiate the list
    initList(&ls_name);

    // Add all the names from the .txt into the list
    while (fscanf(ifp, "%s", buffer) != EOF)
    {
        push(&ls_name, buffer);
    }

    printf("Name %d: %s\n", 1, getNth(&ls_name, 0));

    printAll(&ls_name);

    while (ls_name.first != NULL)
    {
        pop(&ls_name);
    }

    pop(&ls_name);

    fclose(ifp);
    return 0;
}