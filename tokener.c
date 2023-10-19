#include "shell.h"

/**
 * tokener - Separates command recieved from stdin by ;
 * @usrinput: String gathered from stdin
 * Return: Parsed strings to be used as commands
 */
char **tokener(char *uinput)
{
	char *comm
	char **cmdstring;
	int i;
	int buffsize = BUFSIZE;

	if (uinput[0] == ' ' && uinput[_strlen(uinput)] == ' ')
		exit(0);
	if (uinput == NULL)
		return (NULL);
	cmdstring = malloc(sizeof(char *) * buffsize);
	if (!cmdstring)
	{
		free(cmdstring);
		perror("hsh");
		return (NULL);
	}
	comm = _strtok(uinput, ";&\n");
	for (i = 0; command; i++)
	{
		cmdstring[i] = comm;
		comm = _strtok(NULL, ";&\n");
	}
	cmdstring[i] = NULL;

	return (cmdstring);
}
