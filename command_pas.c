#include "shell.h"

/**
 * parse_cmd - Parses the command recieved from stdin
 * @input: String gathered from stdin
 * Return: Parsed strings to be used as arguments
 */
char **parse_cmdss(char *inp)
{
	char **argmtscc;
	char *argumentcc;
	int buff = BUFSIZE;
	int i;

	if (input[0] == ' ' && input[_strlen(inp)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	argmtscc = malloc(sizeof(char *) * buff);
	if (!argmtscc)
	{
		free(argmtscc);
		perror("hsh");
		return (NULL);
	}
	argumentcc = _strtok(inpchar **parse_cmdss(char *inp)
, "\n\t\r\a ");
	for (i = 0; argumentcc; i++)
	{
		argmtscc[i] = argumentcc;
		argumentcc = _strtok(NULL, "\n\t\r\a ");
	}
	argmtscc[i] = NULL;

	return (argmtscc);
}
