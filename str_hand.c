#include "shell.h"

/**
 * _putchar - function that writes the character to stdout
 * @f: The character to print
 * Return: character to standard output
 */
int _putchar(char f)
{
	return (write(1, &f, 1));
}

/**
 * _puts - function that prints a string
 * @sth: pointer to string
 * Return: void
 */
void _puts(char *sth)
{
	int v;

	for (v = 0; sth[v] != '\0'; v++)
	{
		_putchar(sth[v]);
	}
	_putchar('\n');
}

/**
 * _strncpy - function that copies a string
 * @de: destination string
 * @sor: source string
 * @y: number of charaters to be copied
 * Return: copied strings
 */
char *_strncpy(char *de, char *sor, int y)
{
	int v = 0;

	while (v < y && *(sor + v))
	{
		*(de + v) = *(sor + v);
		v++;
	}
	while (v < y)
	{
		*(de + v) = '\0';
		v++;
	}
	return (de);
}

/**
 * _strlen - function that counts the length of a string
 * @m: string input
 * Return: length of string
 */
int _strlen(char *m)
{
	int v;

	for (v = 0; m[v] != '\0'; v++)
	{
		continue;
	}
	return (v);
}

/**
 * _atoi - function to convert string to a integer
 * @f: string input
 * Return: converted integer
 */
int _atoi(char *f)
{
	int v = 0;
	int k = 1; 
	int x;
	unsigned int l = 0;

	while (f[v] != '\0')
	{
		if (f[v] == '-')
		{
			return (2);
		}
		x = f[v] - '0';

		if (l > 0 && !(x >= 0 && x <= 9))
			break;

		if (x >= 0 && x <= 9)
			l = l * 10 + x;

		v++;
	}
	l *= k;
	return (l);
}
