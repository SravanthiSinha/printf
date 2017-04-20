#include "holberton.h"

/**
 * print_string_rot13 - writes a rot13 decoded string  to the screen
 * @s: string to be outputed
 * @count: count
 * Description: writes a rot13 decoded string  to the screen
 * Return: Returns the number of bytes that were written
 */
int print_string_rot13(char *s, int count)
{
	int bytecount;

	bytecount = 0;
	if (s == NULL)
	{
		bytecount = print_str("(null)") - 1;
	}
	else
	{
		bytecount = print_str(rot13(s));
		if (count)
			bytecount -= 1;
	}
	return (bytecount);
}

/**
 * rot13 - Returns a rot13 decoded string  to the screen
 * @s: string to be outputed
 * Description: returns a rot13 decoded string  to the screen
 * Return: Returns the number of bytes that were written
 */
char *rot13(char *s)
{
	int i, len;
	char *str;
	char a;

	len = str_len(s);
	i = 0;
	str = malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		a = (int)s[i];
		if ((a >= 97 && a < 110) || (a >= 65 && a < 78))
			str[i] = (char)(a + 13);
		else if ((a >= 110 && a < 123) || (a >= 78 && a < 91))
			str[i] = (char)(a - 13);
		i++;
	}
	return (str);
}
