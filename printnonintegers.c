#include "holberton.h"

/**
 * print_character - writes a character to the screen
 * @c: character to be outputed
 * Description: writes a character to the screen
 * Return: Returns the number of bytes that were written
 */
int print_character(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - writes a string to stdout.
 * @str: Contains to desired string to write to stdout.
 *
 * Return: length of string excluding null byte.
 */
int print_str(char *str)
{
	int i;
	int len;

	len = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		print_character(str[i]);
		len++;
	}
	return (len);
}
/**
 * print_string - writes a string  to the screen
 * @s: string to be outputed
 * @count: count
 * Description: writes a string to the screen
 * Return: Returns the number of bytes that were written
 */
int print_string(char *s, int count)
{
	int bytecount;

	bytecount = 0;
	if (s == NULL)
		bytecount = print_str("(null)") - 1;
	else
	{
		bytecount = print_str(s);
		if (count)
			bytecount -= 1;
	}
	return (bytecount);
}

/**
 * print_string_rev - writes a string  to the screen
 * @s: string to be outputed
 * @count: count
 * Description: writes a string to the screen
 * Return: Returns the number of bytes that were written
 */
int print_string_rev(char *s, int count)
{
	int bytecount;

	bytecount = 0;
	if (s == NULL)
		bytecount = print_str("(null)") - 1;
	else
	{
		bytecount = print_str(reverse(s));
		if (count)
			bytecount -= 1;
	}
	return (bytecount);
}
