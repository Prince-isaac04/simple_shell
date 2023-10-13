#include "shell.h"

/**
* print_file - Prints a string to a file descriptor
* @instruction: The string to be printed
* This function writes the specified string to a file descriptor.
* Return: None
*/

void  print_file(const char *instruction)
{
	int m = 1;

   write(m, instruction, strlen(instruction));
}
