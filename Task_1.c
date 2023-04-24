#include <stdarg.h>
#include <stdio.h>

/**
 * print_d - prints an integer as a decimal
 * @args: list of arguments
 * Return: number of characters printed
 */
int print_d(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	int div = 1;

	if (n < 0)
	{
		putchar('-');
		count++;
		n = -n;
	}
	while (n / div > 9)
		div *= 10;
	while (div != 0)
	{
		putchar('0' + n / div);
		count++;
		n %= div;
		div /= 10;
	}
	return (count);
}

/**
 * print_i - prints an integer as a decimal
 * @args: list of arguments
 * Return: number of characters printed
 */
int print_i(va_list args)
{
	return (print_d(args));
}

/**
 * _printf - prints formatted output
 * @format: string with format specifiers
 * Return: number of characters printed
 */
int _printf_handler(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'd':
					count += print_d(args);
					break;
				case 'i':
					count += print_i(args);
					break;
				default:
					putchar('%');
					putchar(format[i]);
					count += 2;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

