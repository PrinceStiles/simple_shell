#include "shell.h"

/**
 * list_len - this determines length of linked list
 * @h: the pointer to first node
 * @Return: return the size of list
 */
size_t list_len(const list_t *h)
{
	size_t a = 0; /* initialized */

	while (h)
	{
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * get_node_index - this gets the index of the node
 * @head: this is the list head's pointer
 * @node: this is the node's pointer
 * Return: -1 or the index of node
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t a = 0; /* a is initialized */

	while (head)
	{
		if (head == node)
			return (a);
		head = head->next;
		a++;
	}
	return (-1);
}

/**
 * print_list - this prints all the elements of list_t linked list
 * @h: this is the pointer of the first node
 * Return: this is the size of the list
 */
size_t print_list(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		_puts(convert_num(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)"); /* pointer */
		_puts("\n");
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * node_starts_with - returns the node that the string starts with a prefix
 * @prefix: this is the string to match
 * @node: this is the pointer to the list's head
 * @c: this is the next char after the prefix to match
 * Return: NULL or to match the node
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix); /* p declared */
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * list_to_strings - this returns an array of strings of the list->str
 * @head: this is thr pointer to the first node
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t a = list_len(head), b;
	char **strs;
	char *str;

	if (!head || !a)
		return (NULL);
	strs = malloc(sizeof(char *) * (a + 1));
	if (!strs)
		return (NULL);
	for (a = 0; node; node = node->next, a++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (b = 0; b < a; b++)
				free(strs[b]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[a] = str;
	}
	strs[a] = NULL;
	return (strs);
}

