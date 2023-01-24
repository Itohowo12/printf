#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_char - prints a char
 * @argp: pointer to current variable argument
 *
 * Return: number of characters printed
 */
int _print_char(va_list argp)
{
	int counter = 0;

	_putchar(va_arg(argp, int));
	counter++;

	return (counter);
}

/**
 * _print_string - prints a string
 * @argp: pointer to current variable argument
 *
 * Return: Number of characters printed
 */
int _print_string(va_list argp)
{
	int counter = 0, j;
	char *string;

	string = va_arg(argp, char *);

	for (j = 0; string[j]; j++)
	{
		_putchar(string[j]);
		counter++;
	}
	return (counter);
}

/**
 * _print_decimal - prints an number in base 10
 * @argp: pointer to current variable argument
 *
 * Return: Number of characters printed
 */
int _print_decimal(va_list argp)
{
	int k, size, counter = 0;

	k = va_arg(argp, int);
	size = 1000000000;

	if (k < 0)
	{
		_putchar(45);
		counter++;
		k *= -1;
	}

	do {
		if (size <= k || size == 1)
		{
			_putchar((k / size) % 10 + '0');
			counter++;
		}
		size = size / 10;
	} while (size != 0);

	return (counter);
}

/**
 * _print_int - prints an integer
 * @argp: pointer to current variable argument
 *
 * Return: Number of characters printed
 */
int _print_int(va_list argp)
{
	int k, size, counter = 0;

	k = va_arg(argp, int);
	size = 1000000000;

	if (k < 0)
	{
		_putchar(45);
		counter++;
		k *= -1;
	}

	do {
		if (size <= k || size == 1)
		{
			_putchar((k / size) % 10 + '0');
			counter++;
		}
		size = size / 10;
	} while (size != 0);

	return (counter);
}
