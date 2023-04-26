#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/****************** Constants *******************/
#define UNUSED(x) (void)(x)
/****************** Structures ******************/

/**
 * struct fmt - Struct fmt
 *
 * @fmt: The format.
 * @f: The function associated.
 */
typedef struct fmt
{
	char fmt;
	int (*f)(va_list);
} fmt_t;


/****************** Print_handlers **************/
int _putchar(char c);
int print_percent(va_list args);
int print_char(va_list args);
int print_binary(va_list args);
int print_string(va_list args);
int print_int_helper(long int n);
int print_int(va_list args);
int print_reverse(va_list args);
int handle_printing(const char *fmt, va_list args);
int _printf(const char *format, ...);

#endif
