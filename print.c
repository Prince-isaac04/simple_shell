#include "shell.h"

void  print_file(const char *instruction)
{
	int m = 1;

   write(m, instruction, strlen(instruction));
}
