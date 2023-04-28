#include "main.h"

/**
 * print_int - print an integer
 * @list: list of arguments
 * Return: will print an integr to o/p
 *
 */

int print_int(va_list args)
{
	int n;
	int i, len;
	char *list;

	n = va_arg(args, int);

	if (n == 0)
	{
		print_char('0');
		return (1);
	}

	if (n < 0)
	{
		len = 1;
		print_char('-');
		n = -n;
	}
	else
	{
		len = 0;
	}
	list = malloc(10 * sizeof(char));
	i = 0;

	while (n > 0)
	{
		list[i] = (n % 10) + '0';
		n /= 10;
		i++;
		len++;
	}

	for (i = len - 1; i >= 0; i--)
	{
		print_char(list[i]);
	}

	free(list);

	return (len);
}
