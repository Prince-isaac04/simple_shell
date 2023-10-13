#include "shell.h"

int strn_cmp(const char *str1, const char *str2, size_t m)
{
    while (m > 0 && *str1 && *str2) 
    {
        if (*str1 != *str2) {
            return (*str1 - *str2);
        }
        str1++;
        str2++;
        m--;
    }

    if (m == 0) 
    {
        return 0;
    } else {
        return (*str1 - *str2);
    }
}
