#include "main.h"
/**
 * buf_s - gets the size of the buffer
 * @s: Size
 * @n: Bytes
 */
void buf_s(size_t *s, int n)
{
	if (n >= R_BUF_SIZE)
	{
		*s = n;
	}
	else
		*s = R_BUF_SIZE;
}

/**
 * handle_sign_sigint - handles SIGINT
 * @sig_t: The signal
 */

void handle_sign_sigint(__attribute__((unused)) int sig_t)
{

	if (sig_t == SIGINT)
	{
		printf("\n$ ");
	}
	fflush(stdout);
}

/**
 * _sep - counts the number of commands
 * @cmd: Command
 * Return: Number of commands
 */
int _sep(char *cmd)
{
	int index;

	for (index = 0; index < _strlen(cmd) - 1; index++)
	{
		if (cmd[index] != ' ')
		{
			return (0);
		}
	}
	return (1);
}

/**
 * tokenizer - tokenizer
 * @l: Command line
 * Return: A pointer to the first token
 */

char **tokenizer(char *l)
{
	char **av = NULL, *delim = " ";
	char *tok;
	int index, len = 0;

	for (index = 0; l[index] != '\0'; index++)
		if (l[index] != *delim)
			len++;

	len += 1;
	av = malloc(sizeof(char *) * len);

	if (!av)
		return (0);

	tok = strtok(l, delim);
	index = 0;
	while (tok != NULL)
	{
		av[index] = tok;
		index++;
		tok = strtok(NULL, delim);
	}
	av[index] = NULL;
	return (av);
}
