/**
 **str_cat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be used maximally
 *Return: the concatenated string
 */
char *str_cat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}
