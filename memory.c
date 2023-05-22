#include "shell.h"

/**
 * bfree - this frees a pointer and then NULL the address
 * @ptr: address of pointer to free
 * Return: 1 if freed, else 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
