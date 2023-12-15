#include "shell.h"

/**
 * starts_with - this checks if the needle starts with the haystack
 * @haystack: this is the string to search
 * @needle: this is the substring to find
 * Return: the address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: negative if s1 < s2, positive if s1> s2, and 0 if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2) /* pointer */
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * *_strlen - this returns the length of string
 * @s: the string that length is to be checked
 * Return: int length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
	return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination buffer
 * @src: source buffer
 * Return:this is the pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

