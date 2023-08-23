#include "main.h"

/**
 * find_path - finds a command in PATH
 * @environ: Envrionment
 * Return: A pointer to the command, or new path, or NULL
 */

char *find_path(char **environ)
{
	int index = 0, len = 0;
	char *path;

	while (environ[index] != NULL)
	{
		if (_strncmp(environ[index], "PATH", 4) == 0)
			break;
		index++;
	}

	len = _strlen(environ[index]);

	path = malloc(len - 4);
	if (!path)
	{
		return (NULL);
	}
	_strcpy(path, environ[index] + 5);
	return (path);
}

/**
 * path_arr - create array from PATH
 * @path: PATH
 * Return: A pointer to the first PATH
 */

char **path_arr(char *path)
{
	int index = 0, k = 0;
	char **arr_p, *tok;

	while (path[index])
	{
		if (path[index] == ':')
			k++;
		index++;
	}
	arr_p = malloc(sizeof(char *) * (k + 2));

	index = 0;
	tok = strtok(path, ":");
	while (tok != NULL)
	{
		arr_p[index++] = tok;
		tok = strtok(NULL, ":");
	}
	arr_p[index] = NULL;
	return (arr_p);
}

/**
 * group_cmd - concatonates commads
 * @arr_p: Array of path
 * @cmd: Command
 * Return: A pointer to the first command
 */

char **group_cmd(char **arr_p, char *cmd)
{
	int i = 0, len = 0;
	char **arr, *t;

	while (arr_p[i])
		i++;

	arr = malloc(sizeof(char *) * (i + 2));

	i = 0;
	while (arr_p[i])
	{
		if (i == 0)
		{
			arr[0] = malloc(_strlen(cmd) + 1);
			_strcpy(arr[0], cmd);
		}
		len = _strlen(cmd) + _strlen(arr_p[i]) + 2;
		arr[i + 1] = malloc(len);
		t = malloc(len);
		_strcpy(t, arr_p[i]);
		_strcpy(arr[i + 1], _strcat(_strcat(t, "/"), cmd));
		i++;
		free(t);
	}
	arr[i + 1] = NULL;
	return (arr);
}
