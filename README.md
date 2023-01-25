# _PRINTF FUNCTION

_printf is a variadic function that takes a required argument, the format string, which may contain conversion specifiers that tell the function the number and types of additional arguments as well as how to format them.

## DESCRIPTION

Conversion specifiers are preceded by a '%' character. Other characters in the format string are printed to standard output as is. _printf also returns the number of characters printed. Generally, the order in which conversion specifiers are encountered in the format string should match the position of the variable arguments.

## HOW IT WORKS

_print uses a struct containing the declaration of a pointer to a char and a pointer to a function. When the function iterates through the struct, this will tell _printf how to output its arguments when it encounters a conversion specifier.
