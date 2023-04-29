#include "main.h"

/**
  * print_binary - prints unsigned int in binary
  * @args: va_list containing the unsigned int
  *
  * Return: number of bits printed
  */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int mask = 1;
	int len = 0;

	while ((mask << 1) <= n)
		mask <<= 1;
	while (mask != 0)
	{
		char bit = (n & mask) ? '1' : '0';

		write(1, &bit, 1);
		len++;
		mask >>= 1;
	}

	return (len);
}

/**
 * print_reverse - print a string in reverse
 * @args: the string to print in reverse
 *
 * Return: length of string printed
 */
int print_reverse(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0;

	if (s)
	{
		char *t = s;

		while (*t)
		{
			t++;
			len++;
		}
		while (s < t--)
			_putchar(*t);
	}
	return (len);
}

/**
 * rot13 - performs the ROT13 transformation on a string and returns its length
 * @args: the string to be transformed
 *
 * Return: the length of the transformed string
 */
int rot13(va_list args)
{
	int i;
	char c;
	char *str = va_arg(args, char *);
	int len = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		c = str[i];
		if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
		{
			c += 13;
		}
		else if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
		{
			c -= 13;
		}
		_putchar(c);
		len++;
	}
	return (len - 1);
}
