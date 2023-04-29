#include "main.h"

/**
 * checker - collect all the string and arguments
 * @format: contain all the possible parameters
 * @fun_list: function that can trigger this parameters
 * @args: list of arguments passed to the program
 * @buffer: A place to store the formatted output
 * @buffer_index: A place to store the formatted output too
 * Return: A total count of printer character
 */

#include "main.h"
int checker(const char *format, spec fun_list[], va_list args, char *buffer, int *buffer_index)
{
	int i, j, ret_val;
	int count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; fun_list[j].sign != NULL; j++)
			{
				if (format[i + 1] == fun_list[j].sign[0])
				{
					ret_val = fun_list[j].f(args, buffer, buffer_index);
					if (ret_val == -1)
						return (-1);
					count += ret_val;
					break;
				}
			}
			if (fun_list[j].sign == NULL)
			{
				buffer[*buffer_index] = format[i];
				*buffer_index += 1
					if (*buffer_index == BUFFER_SIZE)
					{
						write(1, buffer, BUFFER_SIZE);
						*buffer_index = 0;
					}
				count++;
			}
			else
				i++;
		}
		else
		{
			buffer[*buffer_index] = format[i];
			*buffer_index += 1;
			if (*buffer_index == BUFFER_SIZE)
			{
				write(1, buffer, BUFFER_SIZE);
				*buffer_index = 0;
			}
			count++;
		}
	}
	return (count);
}
