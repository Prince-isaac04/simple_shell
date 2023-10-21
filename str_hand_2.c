#include "shell.h"

/**
 * _strcmp - function that compares two string
 * @sty1: first string
 * @sty2: second string
 * Return: 0 if identical otherwise how much diffrent
 */
int _strcmp(char *sty1, char *sty2)
{
	int cmp = 0, i;
	int len1, len2;

	len1 = _strlen(sty1);
	len2 = _strlen(sty2);

	if (sty1 == NULL || sty2 == NULL)
		return (1);

	if (len1 != len2)
		return (1);

	for (i = 0; sty1[i]; i++)
	{
		if (sty1[i] != sty2[i])
		{
			cmp = sty1[i] - sty2[i];
			break;
		}
		else
			continue;

	}
	return (cmp);
}

/**
 * _isalpha - function to check if c is alphabet
 * @m: character to check
 * Return: 1 if true 0 if false
 */
int _isalpha(int m)
{
	if (((m >= 97) && (m <= 122)) || ((m >= 65) && (m <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _itoa - funciton that convert integer to character
 * @m: integer to convert
 * Return: character pointer
 */
char *_itoa(unsigned int m)
{
	int v = 0;
	int len = 0;
	char *s;

	len = intlen(m);
	s = malloc(len + 2);

	if (!s)
	{
		free(s);
		return (NULL);
	}
	*s = '\0';

	while (m / 10)
	{
		s[v] = (m % 10) + '0';
		m /= 10;
		v++;
	}

	s[v] = (m % 10) + '0';
	array_rev(s, len);
	s[v + 1] = '\0';

	return (s);
}

/**
 * array_rev - function reverse an array
 * @arry: array to reverse
 * @len: length of array
 */
void array_rev(char *arry, int len)
{
	int v;
	char tmpt;

	for (v = 0; v < (len / 2); v++)
	{
		tmpt = arry[v];
		arry[v] = arry[(len - 1) - v];
		arry[(len - 1) - v] = tmpt;
	}
}

/**
 * intlen - function that determine length of integer
 * @num: given integer
 * Return: length of integer
 */
int intlen(int numb)
{
	int len = 0;

	while (numb != 0)
	{
		len++;
		numb /= 10;
	}
	return (len);
}
