#include "shell.h"

/**
 * en_creation - Creates an array of Enviroment Variables
 * @envir: Array to store Enviroment Variables
 */

void en_creation(char **envir)
{
	int v;

	for (v = 0; environ[v]; v++)
		envir[v] = _strdup(environ[v]);
	envir[v] = NULL;
}

/**
 * en_free - Frees the memory of the created Enviroment Variables array
 * @envir:  Array of Environment variables
 */
void en_free(char **envir)
{
	int v;

	for (v = 0; envir[v]; v++)
	{
		free(envir[v]);
	}
}
