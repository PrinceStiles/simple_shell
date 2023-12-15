#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

#define CMD_NORM	0 /* for command chaining*/
#define CMD_AND	2
#define CMD_OR	1
#define CMD_CHAIN	3

#define READ_BUF_SIZE 1024 /* for r/w buffers */
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define HIST_FILE	".simple_shell_history"
#define	HIST_MAX		4096

#define	USE_GETLINE	0 /* 1 if using system getline() */
#define	USE_STRTOK	0

#define CONVERT_LOWERCASE	1 /* for convert_number() */
#define	CONVERT_UNSIGNED	2

extern char **environ;

/**
 * struct liststr - singly linked list
 * @next: points to nextnode
 * @str: string
 * @num: number field
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
}
list_t;

/**
 * struct passinfo - contains pseudo-arguments to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: str generated from getline containing arguments
 * @argv: array of str generated from arg
 * @path: str path for the current command
 * @argc: arg count
 * @line_count: err count
 * @err_num: the error code for exits
 * @linecount_flag: if on cout this line of input
 * @fname:program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: history node
 * @alias: alias node
 * @env_changed: on if environ was changed
 * @status: reurn status of the last execcuted command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: fd from which to read line input
 * @histcount: history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *alias;
	list_t *history;
	char **environ;
	int env_changed;
	int status;
	int cmd_buf_type;
	int readfd;
	int histcount;
	char **cmd_buf;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}

/**
 * struct builtin - contains builtin string and related function
 * @func: function
 * @type: builtin command flag
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* toem_shloop.c */
int find_builtin(info_t *);
void fork_cmd(info_t *);
void find_cmd(info_t *);
int hsh(info_t *, char **);

/* toem_parser.c */
char *dup_chars(char *, int, int);
int is_cmd(info_t *, char *);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* toem_handle_errors.c */
int _putfd(char c, int fd);
int eput_char(char);
void _eputs(char *);
int _putsfd(char *str, int fd);

/* toem_stringfunc.c */
char *starts_with(const char *, const char *);
int _strcmp(char *, char *);
int _strlen(char *);
char *_strcat(char *, char *);

/* toem_strings1.c */
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strcpy(char *, char *);

/* toem_shell_exits.c */
char *_strncat(char *, char *, int);
char *_strncpy(char *, char *, int);
char *_strchr(char *, char);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_reallocfunc.c */
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
char *_memset(char *, char, unsigned int);

/* toem_memory1.c */
int bfree(void **);

/* toem_builtin1.c */
int my_history(info_t *);
int my_alias(info_t *);

/* toem_atoi.c */
int _atoi(char *);
int _isalphabet(int);
int is_delimiter(char, char *);
int responsive(info_t *);

/* toem_handle_errors1.c */
void print_error(info_t *, char *);
int print_dec(int, int);
char *convert_num(long int, int, int);
void remove_comments(char *);
int error_atoi(char *);

/* toem_builtin.c */
int _myexit(info_t *);
int _myhelp(info_t *);
int _mycd(info_t *);

/* toem_get_line.c */
void sigHandler(int);
int _getline(info_t *, char **, size_t *);
ssize_t get_input(info_t *);

/* toem_get_info.c */
void free_info(info_t *, int);
void set_info(info_t *, char **);
void clear_info(info_t *);

/* toem_get_env.c */
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);
char **get_environ(info_t *);

/* toem_environs.c */
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);
char *get_env(info_t *, const char *);
int my_env(info_t *);

/* toem_history_shell.c */
int read_history(info_t *info);
int write_history(info_t *info);
char *get_history_file(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* toem_vars1.c */
int replace_vars(info_t *);
int replace_alias(info_t *);
int replace_string(char **, char *);
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);

/* toem_list1.c */
size_t print_list(const list_t *);
ssize_t get_node_index(list_t *, list_t *);
char **list_to_strings(list_t *);
list_t *node_starts_with(list_t *, char *, char);
size_t list_len(const list_t *);

/* toem_lists_shell.c */
int delete_node_at_index(list_t **, unsigned int);
list_t *add_node_end(list_t **, const char *, int);
list_t *add_node(list_t **, const char *, int);
size_t print_list_str(const list_t *);
void free_list(list_t **);

#endif



