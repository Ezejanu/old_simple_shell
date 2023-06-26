#include "main.h"

/**
 * _strcpy - A function that copies a string pointed to by @src, including
 *           the terminating null byte, to a buffer pointed to by @dest.
 * @dest: A buffer to copy the string to.
 * @src: The source string to copy.
 *
 * Return: A pointer to the destination string @dest.
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - Function that concatenates two strings
 * @dest: String 1
 * @src: String 2
 * Return: concatenated character
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, dest_len = 0;

	while (dest[i++])
		dest_len++;

	for (i = 0; src[i]; i++)
		dest[dest_len++] = src[i];

	return (dest);
}

/**
 * _strlen - Function to return the length of a string
 * @s: pointer to the string
 * Return: int
 */

int _strlen(char *s)
{
	int length = 0;

	while (*s++)
		length += 1;
	return (length);
}

/**
 * _strdup - Function to duplicate a string
 * @str: String to be duplicated
 *
 * Return: pointer to the duplicated string
 */

char *_strdup(char *str)
{
	int i, length;
	char *duplicate;

	length = _strlen(str);
	duplicate = malloc(sizeof(char) * length + 1);
	if (duplicate == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		duplicate[i] = str[i];
	}
	duplicate[i] = '\0';

	return (duplicate);
}

#include "main.h"

/**
 * _strcmp - Function that compares 2 strings
 * @s1: Strin 1
 * @s2: String 2
 * Return: If str1 < str2,
 *		the negative difference of the first unmatched characters
 *	If str1 > str2,
 *		the positive difference of the first unmatched characters
 *         If str1 == str2, 0.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if( (*s1 - *s2) == 0)
		return (1);
	else
		return (0);
}
