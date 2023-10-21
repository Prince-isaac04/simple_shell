#include "shell.h"

/**
 * _getlin - read input from standard input by user
 * Return: the input on a buffer
 */
char *_getlin()
{
	int s;
	int buffsize = BUFSIZE;
	int ld;
	char a = 0, *buffed, *buff;

	buffed = malloc(buffsize);
	if (buffed == NULL)
	{
		free(buffed);
		return (NULL);
	}
	for (s = 0; a != EOF && a != '\n'; s++)
	{
		fflush(stdin);
		ld = read(STDIN_FILENO, &a, 1);
		if (ld == 0)
		{
			free(buffed);
			exit(EXIT_SUCCESS);
		}
		buffed[s] = a;
		if (buffed[0] == '\n')
			return (insert(buffed));
		if (s >= buffsize)
		{
			buffed = realloc(buffed, (buffsize + 2));
			if (buffed == NULL)
			{
				free(buffed);
				return (NULL);
			}
		}
	}
	buffed[s] = '\0';
	buff = spacess(buffed);
	free(buffed);
	hashtag_hands(buff);
	return (buff);
}

/**
 * insert - Handles newline character input
 * @strn: String to be handled
 * Return: Empty string
 */
char *insert(char *strn)
{
	free(strn);
	return ("\0");
}

/**
 * spacess - Modifies the input string to remove preceeding whitespaces
 * @strm: Input to be modifies
 * Return: Returns the modified string
 */
char *spacess(char *strm)
{
	int s;
	int j = 0;
	char *buffar;

	buffar = malloc(sizeof(char) * (_strlen(strm) + 1));
	if (buffar == NULL)
	{
		free(buffar);
		return (NULL);
	}
	for (s = 0; strm[s] == ' '; s++)
		;
	for (; strm[s + 1] != '\0'; s++)
	{
		buffar[j] = strm[s];
		j++;
	}
	buffar[j] = '\0';
	if (buffar[0] == '\0' || buffar[0] == '#')
	{
		free(buffar);
		return ("\0");
	}
	return (buffar);
}

/**
 * hashtag_hands - function that removes everything after '#'
 * @buffar: input buffer
 * Return: nothing
 */
void hashtag_hands(char *buffar)
{
	int v;

	for (v = 0; buffar[v] != '\0'; v++)
	{
		if (buffar[v] == '#' && buffar[v - 1] == ' ' && buffar[v + 1] == ' ')
		{
			buffar[v] = '\0';
		}
	}
}
