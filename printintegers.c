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
	int bytecount;

	if (!n)
		return (print_character('0') - 1);
	bytecount = 0;
	if (n == 0)
		bytecount++;
	print_number(n);
	while (n != 0)
	{
		n = n / 10;
		bytecount++;
	}
	return (bytecount - 1);
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
	int r, i, bytecount;
	int no;
	char c[] = "0123456789abcdef";
	char s[] = "00000000";

	if (!n)
		return (print_character('0') - 1);
	bytecount = 0;
	i = 7;
	no = 0;
	while (n > 16)
	{
		r = n % 16;
		s[i] = (c[r]);
		i--;
		n = n / 16;
		bytecount++;
	}
	s[i] = c[n];
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != '0')
			no++;
		if (no)
			print_character(*(s + i));
		i++;
	}
	return (bytecount);
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
	int r, i, bytecount;
	int no;
	char c[] = "0123456789ABCDEF";
	char s[] = "00000000";

	if (!n)
		return (print_character('0') - 1);
	bytecount = 0;
	no = 0;
	i = 7;
	while (n > 16)
	{
		r = n % 16;
		s[i] = (c[r]);
		i--;
		n = n / 16;
		bytecount++;
	}
	s[i] = c[n];
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != '0')
			no++;
		if (no)
			print_character(*(s + i));
		i++;
	}
	return (bytecount);
}
