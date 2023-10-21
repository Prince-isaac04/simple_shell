#include "shell.h"

/**
 * _realloces -  reallocates a memory block as aheap  using malloc and free
 *@pt: pointer to a pointer of addresses
 *@b4_size: previous Size Of The Pointer
 *@nex_size: new size of the pointer
 *Return: Pointer to reallocated memory
 */
void *_realloces(void *pt, unsigned int b4_size, unsigned int nex_size)
{
	void *out;

	if (nex_size == b4_size)
		return (pt);
	if (nex_size == 0 && pt)
	{
		free(pt);
		return (NULL);
	}
	out = malloc(nex_size);
	if (out == NULL)
	{
		free(out);
		return (NULL);
	}
	if (pt == NULL)
	{
		put_array(out, '\0', nex_size);
		free(pt);
	}
	else
	{
		_memocpyes(out, pt, b4_size);
		free(pt);
	}
	return (out);
}

/**
 * all_freess - free memory allocated
 * @cmny: array pointer
 * @lin: char pointer
 * Return: Void
 */
void all_freess(char **cmny, char *lin)
{
	free(cmny);
	free(lin);
	cmny = NULL;
	lin = NULL;
}

/**
 * _memocpyes - copy bytes of memory from source to destination
 *@d: destination pointer
 *@srv: source pointer
 *@m: size to be copied
 *Return: pointer to destination
 */
char *_memocpyes(char *d, char *srv, unsigned int m)
{
	unsigned int e;

	for (e = 0; e < m; e++)
	{
		d[e] = srv[e];
	}
	return (d);
}

/**
 * put_array - fill an array by constant byte
 *@l: void pointer
 *@y: int
 *@ln: length for int
 *Return: void pointer
 */
void *put_array(void *l, int y, unsigned int ln)
{
	char *pt = l;
	unsigned int i = 0;

	while (i < ln)
	{
		*pt = y;
		pt++;
		i++;
	}
	return (l);
}

/**
 * _calloces - allocates memory for an array using malloc
 *@siz: size
 *Return: void pointer
 */
void *_calloces(unsigned int siz)
{
	char *w;
	unsigned int k;

	if (siz == 0)
		return (NULL);
	w = malloc(siz);
	if (w == NULL)
		return (NULL);
	for (k = 0; k < siz; k++)
	{
		w[k] = '\0';
	}
	return (w);
}
