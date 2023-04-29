#include "main.h"
#include <stdarg.h>

/** print_octal - function that prints numeral system with a base of 8
 * @list: list of arguments
 * @buffer: Array to handle print
 * @buffer_index: Place to store the numbers
 * Return: Number of character printed
 */
int print_octal(va_list list, char *buffer, int *buffer_index)
{
	unsigned int num;
	int i;
	int count = 0;
	char octal[11];
	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		buffer[(*buffer_index)++] = '0';
		return (1);
	}
	for (i = 0; num > 0; i++)
	{
		octal[i] = (num % 8) + '0';
		num /= 8;
	}
	for (i--; i >= 0; i--)
	{
		buffer[(*buffer_index)++] = octal[i];
		count++;
		if (*buffer_index == BUFFER_SIZE)
		{
			write(1, buffer, BUFFER_SIZE);
			*buffer_index = 0;
		}
	}
	return (count);
}

/** print_hex - function that prints lower hexdecimal
 * @list: list of arguments
 * @buffer: Array to handle print
 * @buffer_index: Place to store the numbers
 * Return: Number of character printed
 */
int print_hex(va_list list, char *buffer, int *buffer_index)
{
	unsigned int num;
	int i;
	int count = 0;
	char hex[8];
	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		buffer[(*buffer_index)++] = '0';
		return (1);
	}
	for (i = 0; num > 0; i++)
	{
		if ((num % 16) < 10)
		hex[i] = (num % 16) + '0';
		else
			hex[i] = (num % 16) + 'a' - 10;
		num /= 16;
	}
	for (i--; i >= 0; i--)
	{
		buffer[(*buffer_index)++] = hex[i];
		count++;
		if (*buffer_index == BUFFER_SIZE)
		{
			write(1, buffer, BUFFER_SIZE);
			*buffer_index = 0;
		}
	}
	return (count);
}

/**
 * print_hex - function that prints upper hexdecimal
 * @list: list of arguments
 * @buffer: Array to handle print
 * @buffer_index: Place to store the numbers
 * Return: Number of character printed
 */
int print_heX(va_list list, char *buffer, int *buffer_index)
{
	unsigned int num;
	int i;
	int count = 0;
	char hex[8];
	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		buffer[(*buffer_index)++] = '0';
		return (1);
	}
	for (i = 0; num > 0; i++)
	{
		if ((num % 16) < 10)
			hex[i] = (num % 16) + '0';
		else
			hex[i] = (num % 16) + 'A' - 10;
		num /= 16;
	}
	for (i--; i >= 0; i--)
	{
		buffer[(*buffer_index)++] = hex[i];
		count++;
		if (*buffer_index == BUFFER_SIZE)
		{
			write(1, buffer, BUFFER_SIZE);
			*buffer_index = 0;
		}
	}
	return (count);
}
