#include "main.h"
/**
 * shell_loop - Looping system
 * @argv: Command
 * @environ: Environment
 */

void shell_loop(char **argv, char **environ)
{
	char *l = NULL;
	size_t buf_s = 0;
	(void) argv;

	while (1)
	{
		if (isatty(0))
		{
			write(1, "$ ", 2);
		}

		if (_line(&l, &buf_s, 0) == -1)
		{
			if (isatty(0))
				_puts("\n");
			break;
		}

		if (_sep(l))
		{
			free(l);
			continue;
		}
		str_cut(l);
		execute_shell_cmd(l, environ);
		free(l);
	}
}

/**
 * execute_shell_cmd - executes commands
 * @line: Structure contains arguments
 * @env: Command
 */

void execute_shell_cmd(char *line, char **env)
{
	int index = 0, status;
	char **arr_path, **av, **cmd;
	char *path;

	path = find_path(env);
	arr_path = path_arr(path);
	av = tokenizer(line);
	cmd = group_cmd(arr_path, av[0]);

	while (cmd[index])
	{
		if (access(cmd[index], X_OK) == 0)
		{
			pid_t my_pid = fork();

			if (my_pid == 0)
			{
				execve(cmd[index], av, env);
				free_elements(av, path, arr_path, cmd);
				exit(1);
			} else
			{
				wait(&status);
				free_elements(av, path, arr_path, cmd);
				return;
			}
		}
		index++;
	}
	perror("./shell");
	free_elements(av, path, arr_path, cmd);
}
