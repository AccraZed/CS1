#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack
{
    char *stack;
    int capacity;
    int size;
} Stack;

Stack *createStack(int capacity)
{
    Stack *ret_stack = calloc(1, sizeof(Stack));

    ret_stack->capacity = capacity;
    ret_stack->stack = malloc(sizeof(char) * capacity);

    return ret_stack;
}

void destroyStack(Stack *s)
{
    free(s->stack);
    free(s);
}

int isFull(Stack *s)
{
    return s->size == s->capacity;
}

int isEmpty(Stack *s)
{
    return s->size == 0;
}

void push(Stack *s, char data)
{
    if (isFull(s))
        return;

    s->stack[s->size++] = data;
}

char pop(Stack *s)
{
    if (isEmpty(s))
        return '\0';

    return s->stack[--s->size];
}

char *reverseString(char *str)
{
    Stack *s = createStack(strlen(str));
    char *ret_str = malloc(sizeof(char) * (1 + s->capacity));
    int i;

    for (i = 0; i < s->capacity; i++)
        push(s, str[i]);

    for (i = 0; i < s->capacity; i++)
        ret_str[i] = pop(s);
    
    ret_str[i] = '\0';
    destroyStack(s);
    
    return ret_str;
}

int main(void)
{
    printf("%s\n", reverseString("cum"));

    return 0;
}