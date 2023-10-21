#include "shell.h"

/**
 * par_cmd - Parses the command recieved from stdin
 * @uput: String gathered from stdin
 * Return: Parsed strings to be used as arguments
 */
char **par_cmd(char *uput)
{
	char **argmt;
	char *argumen;
	int v;
	int buffsize = BUFSIZE;

	if (uput[0] == ' ' && uput[_strlen(uput)] == ' ')
		exit(0);
	if (uput == NULL)
		return (NULL);
	argmt = malloc(sizeof(char *) * buffsize);
	if (!argmt)
	{
		free(argmt);
		perror("hsh");
		return (NULL);
	}
	argumen = _strtok(uput, "\n\t\r\a ");
	for (v = 0; argumen; v++)
	{
		argmt[v] = argumen;
		argumen = _strtok(NULL, "\n\t\r\a ");
	}
	argmt[v] = NULL;

	return (argmt);
}
