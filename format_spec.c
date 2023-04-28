#include "main.h"

/* print character */

/**
 * print_chara - print just one single word
 * @list: list of arguments
 *
 * Return: print one character to o/p
 */

int print_chara(va_list list)
{
	print_char(va_arg(list, int));
	return (1);
}

/* print string */

/**
 * print_string - function to print a string of words
 * @list: list of arguments
 *
 * Return: print words to o/p
 */

int print_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
	str = "(null)";
	return (i);
}

/* print percent */

/**
 * print_percent - print the modulus symbol
 * @list: argument list
 *
 * Return: will return the modulus sign to o/p
 */

int print_percent(__attribute__((unused))va_list list)
{
	print_char('%');
	return (1);
}
