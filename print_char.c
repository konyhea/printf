#include "main.h"

/**
 * print_char - writes the character c to the stdout
 * @c: the character to print
 *
 * Return: on success 1
 */

int print_char(char c)
{
	return (write(1, &c, 1));
}
