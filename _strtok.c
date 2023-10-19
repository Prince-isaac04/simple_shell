#include "shell.h"

/**
 * is_del - function that checks if a character matchs any character
 * @m: character to check
 * @strh: string of delimiters
 * Return: 1 on success, 0 on failure
 */
unsigned int is_del(char m, const char *strh)
{
	unsigned int i;

	for (i = 0; strh[i] != '\0'; i++)
	{
		if (m == strh[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - function that extracts tokens of a string
 * @strh: string
 * @delims: delimiter
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *strh, const char *delims)
{
	static char *toks;
	static char *ntoks;
	unsigned int s;

	if (strh != NULL)
		ntoks = strh;
	toks = ntoks;
	if (toks == NULL)
		return (NULL);
	for (s = 0; toks[s] != '\0'; s++)
	{
		if (is_del(toks[s], delims) == 0)
			break;
	}
	if (ntoks[s] == '\0' || ntoks[s] == '#')
	{
		ntoks = NULL;
		return (NULL);
	}
	toks = ntoks + s;
	ntoks = toks;
	for (s = 0; ntoks[s] != '\0'; s++)
	{
		if (is_del(ntoks[s], delims) == 1)
			break;
	}
	if (ntoks[s] == '\0')
		ntoks = NULL;
	else
	{
		ntoks[s] = '\0';
		ntoks = ntoks + s + 1;
		if (*ntoks == '\0')
			ntoks = NULL;
	}
	return (toks);
}
