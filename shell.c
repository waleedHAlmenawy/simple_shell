#include "main.h"


/**
 * main - entry point
 * @argv: Arguments
 * @argc: Number of arguments
 * @env: Envrionment
 * Return: 0
 */

int main(int argc, char **argv, char **env)
{
	(void)argc;
	signal(SIGINT, handle_sign_sigint);
	shell_loop(argv, env);
	return (0);
}
