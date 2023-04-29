#include "main.h"

/**
 * print_binary - function that convert a number to binary
 * @list: list of arguments
 * @buffer: the memory to store value
 * @buffer_index: the position of the memory
 *
 * Return: return a binary result to o/p
 */

int print_binary(va_list list, char *buffer, int *buffer_index)
{
	unsigned int num;
	int i;
	int count = 0;
	char binary[32];

	num = va_arg(list, unsigned int);
	
	if (num == 0)
	{
		buffer[(*buffer_index)++] = '0';
		return (1)
	}

	for (i = 0; num > 0; i++)
	{
		binary[i] = (num % 2) + '0';
		num /= 2;
	}

	for (i--; i >= 0; i--)
	{
		buffer[(*buffer_index)++] = binary[i];
		count++;

		if (*buffer_index == BUFFER_SIZE)
			{
				write(1, buffer, BUFFER_SIZE);
				*buffer_index = 0;
			}
	}
	
	return (count);	
}
