#include "shell.h"

/**
 * path_cmnder -  Search In $PATH for executable command
 * @cmnd: Parsed input
 * Return: 0 on success or  1 on failure  0
 */
int path_cmnder(char **cmnder)
{
	char *path, *cmnd_dir, *value;
	struct stat buff;

	path = _getenv("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		cmnd_dir = builder(*cmnder, value);
		if (stat(cmnd_dir, &buff) == 0)
		{
			*cmnder = _strdup(cmnd_dir);
			free(cmnd_dir);
			free(path);
			return (0);
		}
		free(cmnd_dir);
		value = _strtok(NULL, ":");
	}
	free(path);
	free(value);
	return (1);
}

/**
 * builderss - Build command
 * @tok: Executable command
 * @value: Directory conatining Command
 * Return: Parsed full path of command or NULL if failed
 */
char *builderss(char *value, char *tok)
{
	size_t see;
	char *cmnd;

	see = _strlen(value) + _strlen(tok) + 2;
	cmnd = malloc(sizeof(char) * len);
	if (cmnd == NULL)
	{
		free(cmnd);
		return (NULL);
	}

	memset(cmnd, 0, len);

	cmnd = _strcat(cmnd, value);
	cmnd = _strcat(cmnd, "/");
	cmnd = _strcat(cmnd, tok);

	return (cmnd);
}

/**
 * _getenv - Gets the value of environment variable by name
 * @name: Environment variable name
 * Return: The value of the environment variable or NULL if failed
 */
char *_getenv(char *name)
{
	size_t name_lengt, value_lengt;
	char *val;
	int i, x, s;

	name_lengt = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], name_lengt) == 0)
		{
			value_lengt = _strlen(environ[i]) - name_lengt;
			val = malloc(sizeof(char) * value_lengt);
			if (!val)
			{
				free(val);
				perror("unable to alloc");
				return (NULL);
			}

			s = 0;
			for (x = name_lengt + 1; environ[i][x]; x++, s++)
			{
				val[s] = environ[i][x];
			}
			val[s] = '\0';

			return (val);
		}
	}
	return (NULL);
}
