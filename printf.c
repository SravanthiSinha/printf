#include "holberton.h"

/**
 * print_o - Choose the format to be printed based on the specifier
 * @ap: its mine damnit
 * @count: the total number of characters written.
 * @specifier: specifier to work on *
 * Description: Choose the format to be printed based on the specifier
 * Return: byte count.
 */
int print_o(va_list ap, int count, char specifier)
{
	int bytecount;

	bytecount = 0;
	if (specifier == 'i')
		bytecount= print_signed_decimal_int(va_arg(ap, signed int));
	else if (specifier == 'd')
		bytecount= print_signed_decimal_int(va_arg(ap, signed int));
	else if (specifier == 'u')
		bytecount= print_unsigned_decimal_int(va_arg(ap, unsigned int));
	else if (specifier == 'o')
		bytecount= print_unsigned_octal(va_arg(ap, unsigned int));
	else if (specifier == 'x')
		bytecount= print_unsigned_hexdecimal_integer(va_arg(ap, unsigned int));
	else if (specifier == 'X')
		bytecount= print_unsigned_hexdecimal_integer_U(va_arg(ap, unsigned int));
	else if (specifier == 'c')
		print_character((char)va_arg(ap, int));
	else if (specifier == 's')
		bytecount= print_string(va_arg(ap, char *), count);
	else if (specifier == 'p')
		bytecount= print_pointeraddress(va_arg(ap, int *));
	else if (specifier == 'b')
		bytecount= print_unsigned_binary(va_arg(ap, unsigned int));
	else if (specifier == '%')
		print_character('%');
	else
	{
		print_character('%');
		bytecount++;
		print_character(specifier);
	}
	return bytecount;
}

/**
 * _printf - Recoded the function printf of the C library
 * @format: This is the string that contains the text to be written to stdout.
 * It can optionally contain embedded format tags that are replaced by the
 * values specified in subsequent additional arguments and formatted as
 * requested.
 * Description: sends formatted output to stdout.
 * Return:If successful, the total number of characters written is returned.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int len;
	int count;
	int bytecount;

	count = 0;
	bytecount = 0;
	if (format)
		va_start(ap, format);
	else
		return (-1);
	for (len = 0; format[len] != '\0'; len++)
	{
		if (format[len] != '%')
			print_character(format[len]);
		else
		{
			len++;
			if (!format[len])
				return (-1);
			count++;
			bytecount += print_o(ap, count,format[len]);
		}
	}
	va_end(ap);
	if (count > 0)
		len -= count;
	len += bytecount;
	return (len);
}
