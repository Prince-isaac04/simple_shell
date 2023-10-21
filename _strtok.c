#include "shell.h"

/**
 * is_delimin - function that checks if a character matchs any character
 * @m: character to check
 * @sty: string of delimiters
 * Return: 1 on success, 0 on failure
 */
unsigned int is_delimin(char m, const char *sty)
{
	unsigned int i;

	for (i = 0; sty[i] != '\0'; i++)
	{
		if (m == sty[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - function that extracts tokens of a string
 * @sty1: string
 * @del: delimiter
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *sty1, const char *del)
{
	static char *tok;
	static char *mtoks;
	unsigned int i;

	if (sty1 != NULL)
		mtoks = sty1;
	tok = mtoks;
	if (tok == NULL)
		return (NULL);
	for (i = 0; tok[i] != '\0'; i++)
	{
		if (is_delimin(tok[i], del) == 0)
			break;
	}
	if (mtoks[i] == '\0' || mtoks[i] == '#')
	{
		mtoks = NULL;
		return (NULL);
	}
	tok = mtoks + i;
	mtoks = tok;
	for (i = 0; mtoks[i] != '\0'; i++)
	{
		if (is_delimin(mtoks[i], del) == 1)
			break;
	}
	if (mtoks[i] == '\0')
		mtoks = NULL;
	else
	{
		mtoks[i] = '\0';
		mtoks = mtoks + i + 1;
		if (*mtoks == '\0')
			mtoks = NULL;
	}
	return (tok);
}
