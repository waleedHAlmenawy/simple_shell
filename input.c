#include "main.h"

/**
 * _line - get l from file
 * @l:array of string
 * @num:buf size
 * @file_des:file descriptor
 * Return:number of byte or -1 if failed
 */
ssize_t _line(char **l, size_t *num, int file_des)
{
	int checker, in, buf_size = R_BUF_SIZE;
	static size_t input;
	char *buf, c = 'm';

	if (input == 0)
		fflush(STDIN_FILENO);
	else
		return (-1);
	input = 0;
	buf = malloc(sizeof(char) * R_BUF_SIZE);
	if (buf == 0)
		return (-1);
	while (c != '\n')
	{
		checker = read(file_des, &c, 1);
		if (checker == -1 || (checker == 0 && input == 0))
		{
			free(buf);
			return (-1);
		}
		if (checker == 0 && input != 0)
		{
			input++;
			break;
		}
		if ((int)input >= buf_size)
		{
			buf_size *= 2;
			buf = realloc(buf, buf_size);
		}
		buf[input++] = c;
	}
	buf[input] = '\0';
	*l = buf;
	buf_s(num, input);
	in = input;
	if (checker != 0)
		input = 0;
	return (in);
}
