#include "main.h"

/**
 * _strdup - duplicates a string
 * @s: String to be duplicated
 * Return: A pointer to the duplicated string
 */

char *_strdup(char *s)
{
	int len = 0;
	char *res;

	if (s == NULL)
		return (NULL);
	len = _strlen(s);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	for (len++; len--;)
		res[len] = *--s;
	return (res);
}

/**
 * _strcpy - copies a string
 * @dest: Destination
 * @src: Source
 * Return: A pointer to the copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == NULL)
	{
		return (dest);
	}

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: Destination
 * @src: Source
 * Return: A pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	char *res = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (res);
}

/**
 * _strncat - concatenates specific bytes of a strings to another
 * @dest: Destination
 * @src: Source
 * @n: Number of bytes
 * Return: A pointer to the concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0, k = 0;
	char *s = dest;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[k] != '\0' && k < n)
	{
		dest[i] = src[k];
		i++, k++;
	}
	if (k < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strlen - gets the length of a string
 * @s: The string
 * Return: The length of the string
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
	{
		return (0);
	}
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

