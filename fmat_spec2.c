#include "main.h"

/**
 * print_int - function that writes an based on the d and i
 * @list: list of arguments
 * @buffer: store the string index
 * @buffer_index: the place the string is stored
 *
 *
 * Return: print an integer to the std o/p
 */
int print_int(va_list list, char *buffer, int *buffer_index)
{
	int num;
	int num_copy;
	int digit_count;
	int i;

	num = va_arg(list, int);

	if (num == 0)
	{
		buffer[(*buffer_index)++] = '0';
		return (1);
	}

	if (num < 0)
	{
		buffer[(*buffer_index)++] = '-';
		num *= -1;
	}

	num_copy = num;
	digit_count = 0;

	while (num_copy != 0)
	{
		digit_count++;
		num_copy /= 10;
	}

	for (i =  digit_count - 1; i >= 0; i--)
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
