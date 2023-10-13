#include "shell.h"

int Cal_Str_Len(const char *m) 
{
    int leng = 0;

    while (m[leng] != '\0') 
    {
        leng++;
    }
    
    return leng;
}
