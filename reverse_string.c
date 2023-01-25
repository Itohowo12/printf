#include "main.h"

/**
 * print_reverse - Prints string in reverse
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_reverse(va_list types, char buffer[], int flags,
		  int width, int precision, int size)
{
	int count = 0, i, j;
	char *str;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	str = va_arg(types, char *);

	for (i = 0; str[i] != '\0'; i++)
	{
		count++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		write(1, &str[j], 1);
	}
	return (count);
}
