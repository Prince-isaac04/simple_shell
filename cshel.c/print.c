#include "shell.h"

<<<<<<< HEAD:print.c
/**
* print_file - Prints a string to a file descriptor
* @instruction: The string to be printed
* This function writes the specified string to a file descriptor.
* Return: None
*/

void  print_file(const char *instruction)
=======
void  shell_print(const char *instruction)
>>>>>>> c2df2a0cdfc2fc9c95426061bdea1baeb0fc8fc8:cshel.c/print.c
{
	int m = 1;

   write(m, instruction, strlen(instruction));
}
