#include "shell.h"

/**
 * _strcpy - function that copies a string
 * @de: destination
 * @srh: source
 * Return: destination
 */
char *_strcpy(char *de, char *srh)
{
	int v = 0;

	while (srh[v])
	{
		de[v] = srh[v];
		v++;
	}
	de[v] = '\0';
	return (de);
}

/**
 * _strcat - function that concatenates two strings
 * @de: first string
 * @srh: second string
 * Return: first string + second string
 */
char *_strcat(char *de, char *srh)
{
	char *out = de;

	while (*de != '\0')
	{
		de++;
	}

	while (*srh != '\0')
	{
		*de = *srh;
		de++;
		srh++;
	}
	*de = '\0';
	return (out);
}

/**
 * _strchr - function that locates character in a string
 * @t: string to be searched
 * @f: character to be located
 * Return: pointer to character
 */
char *_strchr(char *t, char f)
{
	do {
		if (*t == f)
		{
			break;
		}
	}
	while (*t++);
		return (t);
}

/**
 * _strncmp - function that compares n amount of characters of two strig
 * @str0: first string
 * @str1: second string
 * @h: amount of characters to compare
 * Return: 1 if the strings don't match otherwise 0
 */
int _strncmp(const char *str0, const char *str1, size_t h)
{
	size_t b;

	if (str1 == NULL)
		return (-1);

	for (b = 0; b < h && str1[b]; b++)
	{
		if (str0[b] != str1[b])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _strdup - duplicate a string
 * @sth: string
 * Return: duplicated string or Null if failed
 */
char *_strdup(char *sth)
{
	size_t let, v;
	char *str3;

	let = _strlen(sth);
	str3 = malloc(sizeof(char) * (let + 1));
	if (!str3)
	{
		return (NULL);
	}
	for (v = 0; v <= let; v++)
	{
		str3[v] = sth[v];
	}
	return (str3);
}
