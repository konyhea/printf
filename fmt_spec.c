#include "main.h"

/**
 * print_chara - Function that prints conversion specifier chara
 * @list: list of arguments
 * @buffer: stores character at the index
 * @buffer_index: The place the character is stored
 * Return: number of character printed
 */

int print_chara(va_list list, char *buffer, int *buffer_index)
{
	char c;

	c = va_arg(list, int);
	buffer[*(buffer_index)++] = c;
	if (*buffer_index == BUFFER_SIZE)
	{
		write(1, buffer, BUFFER_SIZE);
		*buffer_index = 0;
	}
	return (1);
}

/**
 * print_string - Function that prints string
 * @list: list of srguments
 * @buffer: stores string at the index
 * @buffer_index: The place the character is stored
 * Return: the number of character printed
 */
int print_string(va_list list, char *buffer, int *buffer_index)
{
	char *str;
	int i;

	str = va_arg(list, char *);
	if (str == NULL)
	str = "(null)";

	for (i = 0; str[i]; i++)
	{
		buffer[(*buffer_index)++] = str[i];
		if (*buffer_index == BUFFER_SIZE)
			{
			write(1, buffer, BUFFER_SIZE);
			*buffer_index = 0;
			}
	}

		return (i);
}

/**
 * print_percent - Function that prints percent
 * @list: list of arguments
 * @buffer: stores string at the index
 * @buffer_index: The place the character is stored
 * Return: the number of character printed
 */
int print_percent(va_list list  __attribute__((unused)), char *buffer,
int *buffer_index)
{

	buffer[(*buffer_index)++] = '%';

	if (*buffer_index == BUFFER_SIZE)
	{
	write(1, buffer, BUFFER_SIZE);
	*buffer_index = 0;
	}
	return (1);
}
