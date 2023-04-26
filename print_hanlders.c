#include "main.h"

/**
  * print_char - prints a single char
  * @args: va_list containing the character to print
  *
  * Return: 1
  */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}


/**
 * print_string - prints a string
 * @args: va_list containing the string to print
 *
 * Return: void
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0;

	while (*s)
	{
		write(1, s, 1);
		s++;
		len++;
	}

	return (len);
}

/**
 * print_int - prints an integer
 * @args: va_list containing the integer to print
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int len = 0;

	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}

	if (n / 10)
		len += print_int_helper(n / 10);

	len += write(1, &"0123456789"[n % 10], 1);

	return (len);
}

/**
 * print_int_helper - recursive helper function for print_int
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_int_helper(int n)
{
	int len = 0;

	if (n / 10)
		len += print_int_helper(n / 10);

	len += write(1, &"0123456789"[n % 10], 1);

	return (len);
}

