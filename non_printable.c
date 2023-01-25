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
	int count = 0, len = 0, i, j, k, ascii, temp;
	char *str;
	char *upperhex = "0123456789ABCDEF";
	char *array;

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
			ascii = (int)str[i];
			temp = ascii;

			while (temp != 0)
			{
				temp /= 16;
				len++;
			}

			if (len < 2)
			{
				write(1, "0", 1);
			}

			array = malloc((sizeof(char) * len) + 1);

			if (array == NULL)
			{
				return (-1);
			}

			for (j = 0; j < len; j++)
			{
				array[j] = upperhex[ascii % 16];
				ascii /= 16;
			}
			array[j] = '\0';

			for (k = len - 1; k >= 0; k--)
			{
				write(1, &array[k], 1);
			}
			count += 4;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
	}
	free(array);
	return (count);
}
