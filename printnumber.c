#include "holberton.h"

/**
 * print_number - Prints the unsigned integer.
 * @n: number to be printed.
 * Description: Prints the unsigned integer.
 */
void print_number(unsigned int n)
{
	if (n > 10)
		print_number(n / 10);
	print_character(n % 10 + 48);
}

/**
 * print_unsigned_binary -  print an un signed integer in binary notation
 * @n: number to be printed.
 * Description:  print an un signed decimal integer in binary notation.
 * Return: Length of the number
 */
int print_unsigned_binary(unsigned int n)
{
	int bytecount;

	if (!n)
		return (print_character('0') - 1);
	bytecount = 0;
	if (n == 0)
		bytecount++;
	print_bin(n);
	while (n != 0)
	{
		n = n / 2;
		bytecount++;
	}
	return (bytecount - 1);
}

/**
 * print_unsigned_octal -  print an un signed integer in octal notation
 * @n: number to be printed.
 *
 * Description:  print an un signed integer in octal notation.
 * Return: Length of the number
 */
int print_unsigned_octal(unsigned int n)
{
	int bytecount;

	if (!n)
		return (print_character('0') - 1);
	bytecount = 0;
	if (n == 0)
		bytecount++;
	print_oct(n);
	while (n != 0)
	{
		n = n / 8;
		bytecount++;
	}
	return (bytecount - 1);
}

/**
 * print_int - Function to writes a number to stdout.
 * @n: Contains the number passed to write to stdout.
 *
 * Return: Bytes written.
 */
int print_int(int n)
{
	int len, a, bytecount, digit;

	bytecount = 0;
	if (n < 0)
		bytecount += print_character('-');
	else
		n = -n;
	for (len = 1, a = n; a < -9; len *= 10)
		a /= 10;
	for (a = n; len != 0; len /= 10)
	{
		digit = (a / len) * -1;
		bytecount += print_character(digit + '0');
		a %= len;
	}

	return (bytecount - 1);

}
