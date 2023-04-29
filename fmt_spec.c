#include "main.h"

/**
 * print_chara - Function that prints conversion specifier chara
 * @buffer: stores character at the index
 * @buffer_index: The place the character is stored
 * @Return: number of character printed
 */

int print_chara(va_list list, char *buffer, int *buffer_index)
{
	char c = va_arg(list, int);
	buffer[*buffer_index] = c;
	(*buffer_index)++;
	return (1);
}

/**
 * print_string - Function that prints string
 * @buffer: stores string at the index
 * @buffer_index: The place the character is stored
 * @Return: the number of character printed
 */
int print_string(va_list list, char *buffer, int *buffer_index)
{
	char *str = va_arg(list, char *);
	int length = j;

	if (str == NULL)
		str = "(null)";

	for (j = 0; str[j]; j++)
	{
		buffer[(*buffer_index)++] = str[j];
		if (*buffer_index == BUFFER_SIZE)
		{
			write(1, buffer, BUFFER_SIZE);
			*buffer_index = 0;
		}
	return (1);
}

/**
 * print_string - Function that prints string
 * @buffer: stores string at the index
 * @buffer_index: The place the character is stored
 * @Return: the number of character printed
 */
int print_percent(va_list list, char *buffer, int *buffer_index)
{
	buffer[*buffer_index] = '%';
	(*buffer_index)++;
	return (1);
}
