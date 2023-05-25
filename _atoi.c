#include "shell.h"

/**
 *responsive - returns true if shell is in responsive mode
 *@info: struct address
 *
 *Return: 1 if responsive mode, 0 otherwise
 */

int responsive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *is_delimiter - checks if the character is a delimiter
 *@Char: the character to check
 *@delimiter: the delimiter string
 *Return: 1 if true, 0 if false
 */

int is_delimiter(char Char, char *delimiter)
{
	while (*delimiter)
	{
		if (*delimiter++ == Char)
			return (1);
	}
	return (0);
}

/**
 *_isalphabet - checks for the alphabetic character
 *@Char: the Character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalphabet(int Char)
{
	if ((Char >= 'a' && Char <= 'z') || (Char >= 'A' && Char <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@Str: the string to be converted
 *Return: 0 if no numbers in the string, convert number otherwise
 */

int _atoi(char *Str)
{
	int i, sign = 1, flag = 0;
	unsigned int result = 0;

	for (i = 0; Str[i] != '\0' && flag != 2; i++)
	{
		if (Str[i] == '-')
			sign *= -1;

	if (Str[i] >= '0' && Str[i] <= '9')
	{
		flag = 1;
		result *= 10;
		result += (Str[i] - '0');
	}
	else if (flag == 1)
		flag = 2;
	}

	if (sign == -1)
		return -result;
	else
		return result;
}

