#include "shell.h"

int _strncmps(char *st1, char *st2)
{
	int i;
	int c = 0;

	for (i = 0; st1[i] != '\0' && c == 0; i++)
	{
		c = st1[i] - st2[i];
	}
	return (c);
}

int _strncmp(const char *list1, const char *list2, size_t c) 
{
    while (*list1 != '\0' && *list2 != '\0' && c > 0) 
    {
        if (*list1 != *list2) 
	{
            return (*list1 > *list2) ? 1 : -1;
        }
        list1++;
        list2++;
        c--;
    }

    if (c == 0) 
    {
        return 0;
    } 
    else if (*list1 == '\0' && *list2 == '\0')
    {
        return 0;
    } 
    else if (*list1 == '\0') {
        return -1;
    } 
    else 
    {
        return 1;
    }
}

