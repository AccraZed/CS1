// Amelia Castilla, COP3502, Fall 2020
// Shoutout to Layne Hoelscher for coming up with the name Strint :p

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "Strint.h"

Strint *allocStrint(int num_digits)
{
    Strint *ret;

    // Allocate the strint
    if ((ret = malloc(sizeof(Strint))) ==  NULL) return NULL;

    ret->len = (num_digits / 2) + (num_digits % 2);

    if ((ret->data = malloc(sizeof(u_char) * ret->len)) == NULL)
        return NULL;
    
    return ret;
}

Strint *ullintToStrint(unsigned long long int n)
{
    Strint *ret;
    int i, num_digits = 0;
    unsigned long long int temp = n;

    // Determine the number of digits in n
    do 
    {
        num_digits++;
        temp /= 10;
    } while(temp);

    // Allocate the strint
    if ((ret = allocStrint(num_digits)) == NULL) return NULL;

    // Initialize the values of the strint
    for (i = 0; i < ret->len; i++)
    {
        ret->data[i] = n % 100;
        n /= 100;
    }
    
    return ret;
}

Strint *stringToStrint(char *str)
{
    Strint *ret;
    int i;

    // Allocate the strint
    if ((ret = allocStrint(strlen(str))) == NULL) return NULL;

    // Set all the values from the string to the strint
    for (i = 0; i < ret->len; i++)
    {
        if (str[2 * i + 1] != '\0')
            ret->data[ret->len - i - 1] = 10 * (str[2 * i] - '0') + (str[2 * i + 1] - '0');
        else
            ret->data[ret->len - i - 1] = str[2 * i] - '0';
    }

    return ret;
}

Strint *destroyStrint(Strint *strint)
{
    if (strint == NULL)
        return NULL;

    free(strint->data);
    free(strint);

    return NULL;
}

Strint *addStrint(Strint *a, Strint *b)
{
    int flag = 0;

    // Case 1: len of both A and B are the same and their largest digits added are greater than 98
    if (a->len == b->len && a->data[a->len - 1] + b->data[b->len - 1] > 98)
}

void printStrint(Strint *strint)
{
    int i;

    if (strint == NULL)
        return;

    for (i = strint->len; i > 0; i--)
    {
        if (strint->data[i - 1] < 10 && i - 1 != 0)
            printf("0");
        printf("%d", (int) strint->data[i - 1]);
    }
    printf("\n");
}

int main(void)
{
    Strint *test = ullintToStrint((unsigned long long) 120500);
    printStrint(test);
    destroyStrint(test);
    test = stringToStrint("43098235890743149802340985298059802539085388234");
    printf("Strint printing: ");
    printStrint(test);
    printf("String printing: 43098235890743149802340985298059802539085388234\n");
    destroyStrint(test);
}