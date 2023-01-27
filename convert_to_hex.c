#include "main.h"

/**
 * convert_to_hex - prints a character to standard output
 * @c: character to be converted
 *
 * Return: nothing
 */
void convert_to_hex(char c)
{
	int len = 0, j, k, ascii, temp;
	char *upperhex = "0123456789ABCDEF";
	char *array;

	ascii = (int)c;
	temp = ascii;

	while (temp != 0)
	{
		temp /= 16;
		len++;
	}

	if (len < 2)
		write(1, "0", 1);

	array = malloc((sizeof(char) * len) + 1);

	if (array == NULL)
		return;

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
}
