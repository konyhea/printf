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

	int count;
	spec fun_list[] = {
		{"c", print_chara},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{"S", print_S},
		{NULL, NULL}
	};
	va_list args;
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
		if (format == NULL)
			return (-1);
		va_start(args, format);
		count = checker(format, fun_list, args, buffer,
		&buffer_index);
		va_end(args);
		if (buffer_index > 0)
			write(1, buffer, buffer_index);
		return (count);
}
