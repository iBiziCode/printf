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


