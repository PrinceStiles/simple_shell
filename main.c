#include "shell.h"

/**
 * main - entry point
 * @av: arg vector
 * @ac: arg count
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { {NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0, NULL} };
	int fd = 2;

	asm("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				eput_char('\n');
				eput_char(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info[0].readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}

