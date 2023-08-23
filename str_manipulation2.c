#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if (s1 = s2), -1 if (s1 < s2), 1 if (s1 > s2)
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++, s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	} else if (*s1 < *s2)
	{
		return (-1);
	}
	return (1);
}

/**
 * _strncmp - compare with two string
 * @str1: String
 * @str2: String
 * @num: Number of compared string
 * Return: 0 if (s1 = s2), -1 if (s1 < s2), 1 if (s1 > s2)
 */
int _strncmp(char *str1, char *str2, int num)
{
	int index;

	for (index = 0; index < num; index++)
	{
		if (str1[index] != str2[index])
		{
			return (str1[index] - str2[index]);
		}
	}
	return (0);
}

/**
 * str_cut - trims an array of strings
 * @l: Array of strings
 */

void str_cut(char *l)
{
	int index;

	for (index = 0; l[index] == ' '; index++)
		l++;
	index = _strlen(l) - 1;

	while (l[index] == ' ' || l[index] == '\n')
		index--;
	l[++index] = '\0';
}

/**
 * _putchar - prints a character
 * @c: Character
 * Return: 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @s: String
 */

void _puts(char *s)
{
	int i = 0;

	if (!s)
	{
		return;
	}
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

