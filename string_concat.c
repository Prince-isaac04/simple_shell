#include "shell.h"


char *string_concat(char *destination, const char *root) 
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
    *destination = '\0';
    return final_dest;
}


void _strcat(char *dest, const char *src) 
{
    string_concat(dest, src);
}
