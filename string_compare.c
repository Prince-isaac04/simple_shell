#include <stdio.h>

int comstring(const char *str1, *name) 
{
    while (*str1 != '\0' && *name != '\0') {
        if (*str1 != *name) {
            return 0;
        }
        str1++;
        name++;
    }
    return (*str1 == '\0' && *name == '\0');
}
