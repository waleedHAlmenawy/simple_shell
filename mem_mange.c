#include "main.h"

/**
 * free_strigns - frees array of strings
 * @str_arr: String
 */

void free_strigns(char **str_arr)
{
	size_t i;

	for (i = 0 ; str_arr[i] != NULL ; i++)
		free(str_arr[i]);

	free(str_arr);
}

/**
 * free_elements - frees all elements
 * @av: String
 * @path: path
 * @arr_path: Array of path
 * @cmds: Commands
 */

void free_elements(char **av, char *path, char **arr_path, char **cmds)
{
	free(av), free(path);
	free(arr_path), free_path(cmds);
}

/**
 * free_path - frees array of path
 * @path_arr:the array of path.
 */

void free_path(char **path_arr)
{
	int i = 0;

	while (path_arr[i])
	{
		free(path_arr[i++]);
	}
	free(path_arr[i]);
	free(path_arr);
}
