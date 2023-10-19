#include "shell.h"

/**
 * _putchar - function that writes the character to stdout
 * @z: The character to print
 * Return: character to standard output
 */
int _putchar(char x)
{
	return (write(1, &x, 1));
}

/**
 * _puts - function that prints a string
 * @str: pointer to string
 * Return: void
 */
void _puts(char *sthr)
{
	int i;

	for (i = 0; sthr[i] != '\0'; i++)
	{
		_putchar(sthr[i]);
	}
	_putchar('\n');
}

/**
 * _strncpy - function that copies a string
 * @dest: destination string
 * @src: source string
 * @z: number of charaters to be copied
 * Return: copied strings
 */
char *_strncpy(char *srch, int z, char *des)
{
	int i = 0;

	while (i < z && *(srch + i))
	{
		*(des + i) = *(srch + i);
		i++;
	}
	while (i < z)
	{
		*(des + i) = '\0';
		i++;
	}
	return (des);
}

/**
 * _strlen - function that counts the length of a string
 * @z: string input
 * Return: length of string
 */
int _strlen(char *v)
{
	int i;

	for (i = 0; v[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _atoi - function to convert string to a integer
 * @z: string input
 * Return: converted integer
 */
int _atoi(char vz)
{
	unsigned int l;
	int i = 0, j = 1, x;
	l = 0;

	while (vz[i] != '\0')
	{
		if (vz[i] == '-')
		{
			return (2);
		}
		x = vz[i] - '0';

		if (l > 0 && !(x >= 0 && x <= 9))
			break;

		if (x >= 0 && x <= 9)
			l = l * 10 + x;

		i++;
	}
	l *= j;
	return (l);
}
