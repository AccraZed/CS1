#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *ifp;
    int num_names, i = 0;
    char **names, buffer[1000];

    // Open names file
    if ((ifp = fopen("names.txt","r")) == NULL)
    {
        printf("Error: File \"%s\" not found.\n", "names.txt");
    }
    else
    {
        printf("File \"%s\" found!\n", "names.txt");
    }
    
    // Find out number of names (can we get rid of this?)
    fscanf(ifp, "%d", &num_names);

    names = malloc(sizeof(char *) * num_names);

    // Allocate 2d array and print out the name currently being processed
    for (i = 0; i < num_names; i++)
    {
        fscanf(ifp, "%s", buffer);
        
        names[i] = malloc(sizeof(char) * strlen(buffer) + 1);

        strcpy(names[i], buffer);

        printf(">>>%s<<<\n", names[i]);
    }

    // Free malloc
    for (i = 0; i < num_names; i++)
    {
        free(names[i]);
    }
    
    free(names);

    fclose(ifp);
    return 0;
}