#include <stdio.h>

/**
 * print_array - Print an array of integers
 * @array - Array to be printed
 * @size - The zize of the array
 */
void print_array(int *array, int size)
{
	int i;

	if (array == NULL || size <= 0)
		return;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
			printf(", ");
	}

	printf("\n");
}

/**
 * main - Entry point
 *
 * Return - Always return 0 (Success)
 */
int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6};

	print_array(array, sizeof(array) / sizeof(int));

	return (0);
}

