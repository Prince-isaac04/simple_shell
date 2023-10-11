#include "shell.h"

void  shell_print(const char *instruction)
{
	int m = 1;

   write(m, instruction, strlen(instruction));
}
