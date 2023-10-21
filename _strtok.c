#include "shell.h"

/**
 * is_delimin - function that checks if a character matchs any character
 * @v: character to check
 * @sth: string of delimiters
 * Return: 1 on success, 0 on failure
 */
unsigned int is_delimin(char v, const char *sth)
{
	unsigned int g;

	for (g = 0; sth[g] != '\0'; g++)
	{
		if (v == sth[g])
			return (1);
	}
	return (0);
}

/**
 * _strtok - function that extracts tokens of a string
 * @str1: string
 * @delim: delimiter
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *str0, const char *de)
{
	static char *ctoks;
	static char *tokss;
	unsigned int v;

	if (str0 != NULL)
		ctoks = str0;
	tokss = ctoks;
	if (tokss == NULL)
		return (NULL);
	for (v = 0; tokss[v] != '\0'; v++)
	{
		if (is_delimin(tokss[v], de) == 0)
			break;
	}
	if (ctoks[v] == '\0' || ctoks[v] == '#')
	{
		ctoks = NULL;
		return (NULL);
	}
	tokss = ctoks + v;
	ctoks = tokss;
	for (v = 0; ctoks[v] != '\0'; v++)
	{
		if (is_delimin(ctoks[v], de) == 1)
			break;
	}
	if (ctoks[v] == '\0')
		ctoks = NULL;
	else
	{
		ctoks[v] = '\0';
		ctoks = ctoks + v + 1;
		if (*ctoks == '\0')
			ctoks = NULL;
	}
	return (tokss);
}
