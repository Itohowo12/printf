#include "main.h"

/**
 * print_non_printable - Prints non-printable characters
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[], int flags,
			int width, int precision, int size)
{
	int count = 0, i;
	char *str;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	str = va_arg(types, char *);

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			write(1, "\\", 1);
			write(1, "x", 1);
			convert_to_hex(str[i]);
			count += 4;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
	}
	return (count);
}
