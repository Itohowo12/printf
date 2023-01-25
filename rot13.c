#include "main.h"

/**
 * print_rot13string - Prints a string in rot13
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_rot13string(va_list types, char buffer[], int flags,
		      int width, int precision, int size)
{
	int count = 0, i, j;
	char *str;
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	str = va_arg(types, char *);

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 65 && str[i] <= 90) ||
		    (str[i] >= 97 && str[i] <= 122))
		{
			j = 0;

			while (alpha[j])
			{
				if (str[i] == alpha[j])
				{
					write(1, &rot13[j], 1);
					count++;
					break;
				}
				j++;
			}
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
	}
	return (count);
}
