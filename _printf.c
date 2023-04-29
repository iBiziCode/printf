#include "main.h"

/**
 * handle_printing - prints an argument based on specifier
 * @fmt: formatted string to print the arguments in.
 * @args: list of arguments to be printed
 * Return: number of characters printed (excluding null byte)
 */

int handle_printing(const char *fmt, va_list args)
{
	int count = 0, i;

	fmt_t fmt_spec[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'b', print_binary},
		{'r', print_reverse}, {'R', rot13}, {'\0', NULL}
	};

	for (i = 0; fmt_spec[i].fmt != '\0'; i++)
		if (*fmt == fmt_spec[i].fmt)
			return (fmt_spec[i].f(args));
	count += write(1, "%", 1);
	count += write(1, fmt, 1);

	return (count);
}

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 *
 * Return: number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);



	if (!format)
		return (-1);

	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			count += handle_printing(format, args);
		}
		else
		{
			count += write(1, format, 1);
		}
	}

	va_end(args);

	return (count);
}
