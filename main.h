#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _print_int(va_list argp);
int _print_decimal(va_list argp);
int _print_string(va_list argp);
int _print_char(va_list argp);
int _putchar(char c);
int _print_unsigned(va_list argp);
int _print_ub(va_list argp);
int _print_uo(va_list argp);
int _print_ux(va_list argp);
int _print_uX(va_list argp);

/**
 * struct conversion - Struct conversion
 *
 * @type: The datatype
 * @p: The function associated with the datatype
 */
typedef struct conversion
{
    char *type;
    int (*p)(va_list);
} f_t;

#endif