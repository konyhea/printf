#include "main.h"

/* conversion specifier */

/**
 * print_number - function that print an unsigned int in dp
 * @n: the number in question
 *
 * Return: Always success 0
 */
int print_number(unsigned int n)
{
	int len;

	len = 0;

	if (n / 10 != 0)
	len += print_number(n / 10);
	print_char((n % 10) + '0');

	return (len + 1);
}

/**
 * print_unsigned - function that print an unsigned int
 * @list: list of arguments
 *
 * Return: return the value of an unsigned int
 */

int print_unsigned(va_list list)
{
	unsigned int num;
	int len;

	len = 0;
	num = va_arg(list, unsigned int);

	len += print_number(num);
	return (len);
}
