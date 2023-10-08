#include "shell.h"

int cal_Str_Len(const char *m) 
{
    int leng = 0;

    while (m[leng] != '\0') 
    {
        leng++;
    }
    
    return leng;
}
