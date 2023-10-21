#include "shell.h"

/**
 * tokener - Separates command recieved from stdin by ;
 * @uinput: String gathered from stdin
 * Return: Parsed strings to be used as commands
 */
char **tokener(char *uinput)
{
	char **cmdstring;
	char *comm;
	int v;
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
	for (v = 0; comm; v++)
	{
		cmdstring[v] = comm;
		comm = _strtok(NULL, ";&\n");
	}
	cmdstring[v] = NULL;

	return (cmdstring);
}
