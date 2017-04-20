#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef int bool;
#define true 1
#define false 0

void print_oct(unsigned int n);
void print_bin(unsigned int n);
char *integer_str(int num, char *str);
int print_signed_decimal_int(signed int);
int print_unsigned_decimal_int(unsigned int);
int print_unsigned_octal(unsigned int);
int print_unsigned_binary(unsigned int);
int print_unsigned_hexdecimal_integer(unsigned int);
int print_unsigned_hexdecimal_integer_U(unsigned int);
int print_int(int n);
int print_character(char);
int print_str(char *str);
int print_string(char *, int count);
int print_pointeraddress(int *);
void print_number(unsigned int);
void swap(char *a, char *b);
int is_number(char c, int option);
int string_to_integer(char *s);
int _printf(const char *format, ...);
int print_o(va_list ap, int count, char specifier);
char *string_concat(char *dest, char *src);
int str_len(const char *s);
int str_ncomp(char *s1, char *s2, int k);
char *reverse(char *str);
char *string_dup(char *str);
int print_string_rev(char *s, int count);
int print_string_rot13(char *s, int count);
char *rot13(char *s);
#endif
