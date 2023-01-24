#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - produces output according to a format.
 * @format: a character string composed of zero or more directives
 *
 * Return: the number of characters printed excluding the null byte
 */
int _printf(const char *format, ...)
{
	va_list args;
	int counter = 0, i = 0, j;
	f_t specifiers[] = {
		{"c", _print_char},
		{"s", _print_string},
		{"d", _print_decimal},
		{"i", _print_int},
		{"u", _print_unsigned},
		{"b", _print_ub},
		{"o", _print_uo},
		{"x", _print_ux},
		{"X", _print_uX},
		{NULL, NULL}
	};

	va_start(args, format);
	if (format != NULL)
	{
		while (format[i])
		{
			if (format[i] == 37)
			{
				if (format[i + 1] == 37)
				{
					_putchar(37);
					counter++;
					i += 2;
				}
				else
				{
					j = 0;

					while (specifiers[j].type != NULL)
					{
						if (format[i + 1] == *specifiers[j].type)
						{
							counter += specifiers[j].p(args);
							i += 2;
							break;
						}
						j++;
					}
				}
			}
			else
			{
				_putchar(format[i]);
				counter++;
				i++;
			}
		}
		va_end(args);
		return (counter);
	}
	return (-1);
}
