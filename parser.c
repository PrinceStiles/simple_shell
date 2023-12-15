#include "shell.h"

/**
 *dup_chars - this duplicates chars
 *@pathstr: PATH string
 *@start: the start index
 *@stop: the stop index
 *Return: this is the pointer to the new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
		int i = 0, k = 0; /* var initialized */

		for (k = 0, i = start; i < stop; i++)
			if (pathstr[i] != ':')
				buf[k++] = pathstr[i];
		buf[k] = 0;
		return (buf);
}

/**
 * is_cmd - this determines if file is an executable command
 * @info: info struct
 * @path: path to file
 * Return: 1 if true, else o
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * find_path - this finds the cmd in the path string
 * @info: this is the info struct
 * @pathstr: this is the path string
 * @cmd: this is the cmd  to find
 * Return: this is the full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0; /* var initialized to 0 */
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

