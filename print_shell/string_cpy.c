#include "shell.h"

void copStr(char *det, const char *sor)
{
    int i;
    
    i = 0;
    while (sor[i] != '\0')
    {
        det[i] = sor[i];
        i++;
    }
    det[i] = '\0';
}
