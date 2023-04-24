#include "main.h"

/**
 * _printLettler - writes a letter
 * @c: the letter
 * Return: 1
 */
int _printLettler(char c)
{
	return (write(1, &c, 1));
}
/**
 * _printWord - prints a word
 * @s: the letters
 * Return: numbers of letters
 */
int _printWord(char *s)
{
	int i = 0;

	if (s == NULL)
	s = "(null)";

	while (s[i])
	{
	_printLettler(s[i]);
	i++;
	}

	return (i);
}

/**
 * _printInt - prints an integer
 * @n: the integer
 * Return: number of characters printed
 */
int _printInt(int n)
{
	int count = 0;
	int digit;
	int sign = 1;

	if (n < 0)
	{
		sign = -1;
		n = -n;
		count += _printLettler('-');
	}

	if (n == 0)
	{
		count += _printLettler('0');
		return (count);
	}

	digit = n % 10;
	n = n / 10;

	if (n > 0)
	{
		count += _printInt(n);
	}

	count += _printLettler(digit + '0');

	return (count * sign);
}

/**
 * _printf - prints the needs
 * @format: the format string
 * Return: number of letters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += _printLettler(va_arg(args, int));
					break;
				case 's':
					count += _printWord(va_arg(args, char *));
					break;
				case '%':
					count += _printLettler('%');
					break;
				default:
					return (-1);
			}
		}
		else
		{
			count += _printLettler(format[i]);
		}
		i++;
	}

	va_end(args);

	return (count);
}
