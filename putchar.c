#include "shell.h"

void _put(char *c)
{
	write(1, &c, 1);
}

