#include "main.h"

/**
 * checker - collect all the string and arguments
 * @format: contain all the possible parameters
 * @fun_list: function that can trigger this parameters
 * @args: list of arguments passed to the program
 *
 * Return: A total count of printer character
 */

int checker(const char *format, spec fun_list[], va_list args)
{
	int i, j, ret_val;
	int count;

	count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; fun_list[j].sign != NULL; j++)
			{
				if (format[i + 1] == fun_list[j].sign[0])
				{
					ret_val = fun_list[j].f(args);
					if (ret_val == -1)
					return (-1);
					count += ret_val;
					break;
				}
			}
		
	if (fun_list[j].sign == NULL && format[i + 1] != ' ')
		{
			if (format [i + 1] != '\0')
			{
				print_char(format[i]);
				print_char(format[i + 1]);

				count = count + 2;
			}
			else
			return (-1);
		}
		i = i + 1;
		}

		else
		{
			print_char(format[i]);
			count++;
		}
	}
	return (count);
}
