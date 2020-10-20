#ifndef __STRINT_H
#define __STRINT_H

typedef struct Strint
{
    unsigned char *data;
    int len;
} Strint;

// Functional Prototypes

// Input: an int detailing the number of digits to be allocated
// Return: A dynamically allocated strint with initialized strint->len and allocated strint->data 
Strint *allocStrint(int num_digits);

// Input: An unsigned long long int n with no leading zeroes
// Return: An address to a Strint with n converted into char array form
Strint *ullintToStrint(unsigned long long int n);

// Input: A string consisting of a number with no leading zeroes
// Return: An address to a Strint with str converted into char array form
Strint *stringToStrint(char *str);

// Input: A Strint
// Return: NULL 
Strint *destroyStrint(Strint *strint);

// Input: 2 Strints
// Output: An address to a new strint containing the sum of *a and *b
Strint *addStrint(Strint *a, Strint *b);

// Input: A Strint
// Output: The value stored in the Strint
void printStrint(Strint *strint);

#endif