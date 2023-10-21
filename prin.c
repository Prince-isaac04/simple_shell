#include "shell.h"

/**
 * disp_number - Prints unsigned integers using _putchar function
 * @g: Unsigned integer to be printed
 */
void disp_number(unsigned int g)
{
	unsigned int v = g;

	if ((v / 10) > 0)
		disp_number(v / 10);

	_putchar(v % 10 + '0');
}

/**
 * displ_number_int - Prints integers using _putchar function
 * @y: Integer to be printed
 */
void displ_number_int(int y)
{
	unsigned int g = y;

	if (y < 0)
	{
		_putchar('-');
		g = -g;
	}
	if ((g / 10) > 0)
		disp_number(g / 10);

	_putchar(g % 10 + '0');
}

/**
 * echo_printer_pro - Executes built-in echo function
 * @cmns: Parsed Command
 * Return: 0 Upon Success -1 Upon Failure
 */
int echo_printer_pro(char **cmns)
{
	pid_t seyipid;
	int st;

	seyipid = fork();
	if (seyipid == 0)
	{
		if (execve("/bin/echo", cmns, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (seyipid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(seyipid, &st, WUNTRACED);
		} while (!WIFEXITED(st) && !WIFSIGNALED(st));
	}
	return (1);
}
