#include "shell.h"


char *string_concat(char *destination, char *root) 
{
    char *final_dest = destination;

    while (*destination != '\0') 
    {
        destination++;
    }
    while (*root != '\0') 
    {
        *destination = *root;
        destination++;
        root++;
    }
    *destinatination = '\0';
    return final_dest;
}

