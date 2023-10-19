#include "shell.h"

/**
 * _strcmp - function that compares two string
 * @str1: first string
 * @str2: second string
 * Return: 0 if identical otherwise how much diffrent
 */
int _strcmp(char *str1, char *str2)
{
	int cmps = 0;
	int i, len1, len2;

	len1 = _strlen(str1);
	len2 = _strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);

	if (len1 != len2)
		return (1);

	for (i = 0; str1[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			cmps = str1[i] - str2[i];
			break;
		}
		else
			continue;

	}
	return (cmp);
}

/**
 * _isalpha - function to check if c is alphabet
 * @z: character to check
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
 * @z: integer to convert
 * Return: character pointer
 */
char *_itoa(unsigned int v)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(v);
	s = malloc(len + 2);

	if (!s)
	{
		free(s);
		return (NULL);
	}
	*s = '\0';

	while (v / 10)
	{
		s[i] = (v % 10) + '0';
		z /= 10;
		i++;
	}

	s[i] = (v % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';

	return (s);
}

/**
 * array_rev - function reverse an array
 * @arr: array to reverse
 * @len: length of array
 */
void array_rev(char *arr, int lens)
{
	int i;
	char me;

	for (i = 0; i < (lens / 2); i++)
	{
		me = arr[i];
		arr[i] = arr[(lens - 1) - i];
		arr[(lens - 1) - i] = me;
	}
}
