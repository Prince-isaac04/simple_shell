#include "shell.h"

/**
 * history - write file with user inputs
 * @userinput: user input
 * Return: 0 on success -1 if failed
 */
int histor(char *uinput)
{
	char *filenames = ".simple_shell_history";
	ssize_t fd;
	int len = 0;
	ssize_t w;

	if (!filenames)
		return (-1);
	fd = open(filenames, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (uinput)
	{
		while (uinput[len])
			len++;
		w = write(fd, uinput, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
