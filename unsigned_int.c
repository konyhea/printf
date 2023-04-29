#include "main.h"

/**
 * print_unsigned - function that print d and i conversion specifier
 * @list: list of arguments
 * @buffer: the memory to store value
 * @buffer_index: the position of the stored char
 * Return: print an int and d
 */

int print_unsigned(va_list list, char *buffer, int *buffer_index)
{
	unsigned int num;
	int digit_count;
	int i;

	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		buffer[(*buffer_index)++] = '0';
		return (1);
	}

	digit_count = 0;
	for (i = num; i != 0; i /= 10)
		digit_count++;

	for (i = digit_count - 1; i >= 0; i--)
	{
		buffer[(*buffer_index) + i] = (num % 10) + '0';
		num /= 10;

		if (*buffer_index == BUFFER_SIZE)
		{
			write(1, buffer, BUFFER_SIZE);
			*buffer_index = 0;
		}
	}
	*buffer_index += digit_count;
	return (digit_count);
}
