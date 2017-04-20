#include "holberton.h"

/**
 * print_signed_decimal_int -  print an signed decimal integer
 * @n: number to be printed.
 * Description: print an signed decimal integer
 * Return: Length of the number
 */
int print_signed_decimal_int(signed int n)
{
	int bytecount;

	bytecount = 0;
	if (!n)
		bytecount = print_character('0') - 1;
	else
		bytecount = print_int(n);
	return (bytecount);
}

/**
 * print_unsigned_decimal_int -  print an un signed decimal integer
 * @n: number to be printed.
 * Description:  print an un signed decimal integer
 * Return: Length of the number
 */
int print_unsigned_decimal_int(unsigned int n)
{
	if (!n)
		return (print_character('0') - 1);
	return (print_int(n));
}

/**
 * print_unsigned_hexdecimal_integer -  print an un signed integer
 *					 in hexadecimal notation
 * @n: number to be printed.
 * Description:  print an un signed integer in hexadecimal notation
 * Return: Length of the number
 */
int print_unsigned_hexdecimal_integer(unsigned int n)
{
	int r, i, k;
	int no;
	char c[] = "0123456789abcdef";
	char s[] = "00000000";

	i = 7;
	k = 0;
	no = 0;
	while (n > 16)
	{
		r = n % 16;
		s[i] = (c[r]);
		i--;
		n = n / 16;
	}
	s[i] = c[n];
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != '0')
			no++;
		if (no)
			print_character(*(s + i));
		k++;
		i++;
	}
	return (k);
}

/**
 * print_unsigned_hexdecimal_integer_U -  print an un signed integer
 *					 in hexadecimal notation
 * @n: number to be printed.
 *
 * Description:  print an un signed integer in hexadecimal notation
 * Return: Length of the number
 */
int print_unsigned_hexdecimal_integer_U(unsigned int n)
{
	int r, i, k;
	int no;
	char c[] = "0123456789ABCDEF";
	char s[] = "00000000";

	i = 7;
	k = 0;
	while (n > 16)
	{
		r = n % 16;
		s[i] = (c[r]);
		i--;
		n = n / 16;
	}
	s[i] = c[n];
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != '0')
			no++;
		if (no)
			print_character(*(s + i));
		k++;
		i++;
	}
	return (k);
}
