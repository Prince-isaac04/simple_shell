#include "shell.h"

/**
 * _strcpy - function that copies a string
 * @dest: destination
 * @src: source
 * Return: destination
 */
char *_strcpy(char *desht, char *src)
{
	int i;
       i = 0;

	while (src[i])
	{
		desht[i] = src[i];
		i++;
	}
	desht[i] = '\0';
	return (dest);
}

/**
 * _strcat - function that concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: first string + second string
 */
char *_strcat(char *dest, char *src)
{
	char *v;
	v = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (v);
}

/**
 * _strchr - function that locates character in a string
 * @z: string to be searched
 * @a: character to be located
 * Return: pointer to character
 */
char *_strchr(char *a, char s)
{
	do {
		if (*s == a)
		{
			break;
		}
	} while (*s++);
	return (s);
}

/**
 * _strncmp - function that compares n amount of characters of two strings
 * @str1: first string
 * @str2: second string
 * @z: amount of characters to compare
 * Return: 1 if the strings don't match otherwise 0
 */
int _strncmp(const char *str2, const char *str1, size_t y)
{
	size_t i;

	if (str1 == NULL)
		return (-1);

	for (i = 0; i < y && str2[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _strdup - duplicate a string
 * @str: string
 * Return: duplicated string or Null if failed
 */
char *_strdup(char *str)
{
	size_t len;
	char *str2;
	size_t i;

	len = _strlen(str);
	strh2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}
	for (i = 0; i <= len; i++)
	{
		strh2[i] = str[i];
	}
	return (strh2);
}
