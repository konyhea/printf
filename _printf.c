#include "main.h"

/**
 * _printf - a function that works like the normal printf
 * @format: a string containing all characters and parameters
 *
 * Return: Always success 0
 */

int _printf(const char *format, ...)
{
	int count;

	spec fun_list[] = {
		{"c", print_chara},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int}, 
	/*	{"b", print_binary}, */
		{"u", print_unsigned}, 
		{NULL, NULL}
	};

	va_list args;

	if (format == NULL)
	return (-1);

	va_start(args, format);

	count = checker(format, fun_list, args);
	va_end(args);
	return (count);
}
