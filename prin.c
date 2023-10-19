#include "shell.h"

/**
 * print_num - Prints unsigned integers using _putchar function
 * @m: Unsigned integer to be printed
 */
void print_num(unsigned int m)
{
	unsigned int x = m;

	if ((x / 10) > 0)
		print_num(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * print_number_int - Prints integers using _putchar function
 * @z: Integer to be printed
 */
void print_number_inter(int y)
{
	unsigned int x = y;

	if (y < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * e_printer - Executes built-in echo function
 * @cmnd: Parsed Command
 * Return: 0 Upon Success -1 Upon Failure
 */
int e_printer(char **cmnd)
{
	pid_t sepid;
	int status;

	sepid = fork();
	if (sepid == 0)
	{
		if (execve("/bin/echo", cmnd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (sepid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
