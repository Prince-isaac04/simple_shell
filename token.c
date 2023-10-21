#include "shell.h"

/**
 * tokener - Separates command recieved from stdin by ;
 * @uinput: String gathered from stdin
 * Return: Parsed strings to be used as commands
 */
char **tokener(char *uinput)
{
	int buffsizer = BUFSIZE;
	char *commd;
	char **cmdstrig;
	int s;

	if (uinput[0] == ' ' && uinput[_strlen(uinput)] == ' ')
		exit(0);
	if (uinput == NULL)
		return (NULL);
	cmdstrig = malloc(sizeof(char *) * buffsizer);
	if (!cmdstrig)
	{
		free(cmdstrig);
		perror("hsh");
		return (NULL);
	}
	commd = _strtok(uinput, ";&\n");
	for (s = 0; commd; s++)
	{
		cmdstrig[s] = commd;
		commd = _strtok(NULL, ";&\n");
	}
	cmdstrig[s] = NULL;

	return (cmdstrig);
}
