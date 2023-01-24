#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - prints a character to standard output
 * @c: character to be printed
 *
 * Return: the function
 */
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

/**
 * _print_unsigned - prints an integer as an unsigned decimal
 * @argp: pointer to current variable argument
 *
 * Return: Number of characters printed
 */
int _print_unsigned(va_list argp)
{
	int counter = 0;
	unsigned int k, size;

	k = va_arg(argp, int);

	size = 1000000000;

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
 * _print_ub - prints an integer as unsigned binary
 * @argp: pointer to current variable argument
 *
 * Return: Number of characters printed
 */
int _print_ub(va_list argp)
{
	int counter = 0, a = 0, i, j;
	unsigned int k, temp;
	char *array;

	k = va_arg(argp, int);
	temp = k;

	while (temp != 0)
	{
		temp /= 2;
		a++;
	}

	array = malloc((sizeof(char) * a) + 1);

	if (array == NULL)
	{
		return (-1);
	}

	for (i = 0; i < a; i++)
	{
		array[i] = (k % 2) + '0';
		k /= 2;
	}
	array[i] = '\0';

	for (j = a - 1; j >= 0; j--)
	{
		_putchar(array[j]);
		counter++;
	}
	free(array);
	return (counter);
}

/**
 * _print_uo - prints an integer as an unsigned octal
 * @argp: pointer to current variable argument
 *
 * Return: Number of characters printed
 */
int _print_uo(va_list argp)
{
	int counter = 0, a = 0, i, j;
	unsigned int k, temp;
	char *array;

	k = va_arg(argp, int);
	temp = k;

	while (temp != 0)
	{
		temp /= 8;
		a++;
	}

	array = malloc((sizeof(char) * a) + 1);

	if (array == NULL)
	{
		return (-1);
	}

	for (i = 0; i < a; i++)
	{
		array[i] = (k % 8) + '0';
		k /= 8;
	}
	array[i] = '\0';

	for (j = a - 1; j >= 0; j--)
	{
		_putchar(array[j]);
		counter++;
	}
	free(array);
	return (counter);
}

/**
 * _print_ux - prints an integer as unsigned hex (lowercase)
 * @argp: pointer to current variable argument
 *
 * Return: Number of characters printed
 */
int _print_ux(va_list argp)
{
	int counter = 0, a = 0, i, j;
	unsigned int k, temp;
	char *lowerhex = "0123456789abcdef";
	char *array;

	k = va_arg(argp, int);
	temp = k;

	while (temp != 0)
	{
		temp /= 16;
		a++;
	}

	array = malloc((sizeof(char) * a) + 1);

	if (array == NULL)
	{
		return (-1);
	}

	for (i = 0; i < a; i++)
	{
		array[i] = lowerhex[k % 16];
		k /= 16;
	}
	array[i] = '\0';

	for (j = a - 1; j >= 0; j--)
	{
		_putchar(array[j]);
		counter++;
	}
	free(array);
	return (counter);
}

/**
 * _print_uX - prints an integer as unsigned hex (uppercase)
 * @argp: pointer to current variable argument
 *
 * Return: Number of characters printed
 */
int _print_uX(va_list argp)
{
	int counter = 0, a = 0, i, j;
	unsigned int k, temp;
	char *upperhex = "0123456789ABCDEF";
	char *array;

	k = va_arg(argp, int);
	temp = k;

	while (temp != 0)
	{
		temp /= 16;
		a++;
	}

	array = malloc((sizeof(char) * a) + 1);

	if (array == NULL)
	{
		return (-1);
	}
	for (i = 0; i < a; i++)
	{
		array[i] = upperhex[k % 16];
		k /= 16;
	}
	array[i] = '\0';

	for (j = a - 1; j >= 0; j--)
	{
		_putchar(array[j]);
		counter++;
	}
	free(array);
	return (counter);
}
