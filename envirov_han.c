#include "shell.h"

/**
 * enviro_line - Creates an array of Enviroment Variables
 * @enviro: Array to store Enviroment Variables
 */

void enviro_line(char **environ)
{
	int i;

	for (i = 0; environ[i]; i++)
		environ[i] = _strdup(environ[i]);
	enviro[i] = NULL;
}

/**
 * enviro_free - Frees the memory of the created Enviroment Variables array
 * @enviro:  Array of Environment variables
 */
void enviro_free(char **environs)
{
	int j;

	for (j = 0; environs[j]; j++)
	{
		free(environs[j]);
	}
}
