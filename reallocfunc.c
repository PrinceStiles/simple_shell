#include "shell.h"

/**
 * ffree - this frees string of strings
 * @pp: the string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - this reallocates a block of memory
 * @ptr: the pointer
 * @old_size: previous block byte size
 * @new_size: new block byte size
 * Return: pointer to old block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

/**
 * *_memset - this fills the memory with a constant byte
 * @s: this is the pointer to the mem area
 * @b: this is the byte to fill *s with
 * @n: this is the amount of bytes to be filled
 * Return: (s) a poiner to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

