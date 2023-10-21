#include "shell.h"

/**
 * histor - write file with user inputs
 * @uinput: user input
 * Return: 0 on success -1 if failed
 */
int histor(char *uinput)
{
	char *filenam = ".simple_shell_history";
	ssize_t ld, w;
	int l = 0;

	if (!filenam)
		return (-1);
	ld = open(filenam, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (ld < 0)
		return (-1);
	if (uinput)
	{
		while (uinput[l])
			l++;
		w = write(ld, uinput, l);
		if (w < 0)
			return (-1);
	}
	return (1);
}
