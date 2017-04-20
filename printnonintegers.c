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
 * print_pointeraddress - writes an address of an pointer
 * @p: pointer of type int*
 * Description: writes a address of an pointer
 * Return: Returns the number of bytes that were written
 */
int print_pointeraddress(int *p)
{
	int divide;
	int bytecount;
	unsigned int *x = (unsigned int *)(&p);

	if (!p)
		return (print_str("(nil)") - 1);
	bytecount = 0;
	divide = sizeof(void *) / sizeof(unsigned int);
	write(1, "0x", 2);
	for (divide--; divide >= 0; divide--)
	{
		bytecount += print_unsigned_hexdecimal_integer(*(x + divide));
	}
	return (bytecount + 3);
}
