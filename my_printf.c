#include <unistd.h>
#include <stdarg.h>

/**
 * my_printf - A custom implementation of printf to print formatted strings.
 * @format: The format string containing text and format specifiers.
 * @...: Additional arguments based on format specifiers.
 *
 * Description: This function is a simplified version of printf that only
 * supports a limited set of format specifiers. It writes the formatted
 * string to standard output.
 *
 * Return: The number of characters written.
 */
int my_printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str;
	int num;
	char c;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'd')
			{
				int len = 0, i;
				char buffer[12];

				num = va_arg(args, int);

				if (num < 0)
				{
					write(STDERR_FILENO, "-", 1);
					count++;
					num = -num;
				}

				do {
					buffer[len++] = (num % 10) + '0';
					num /= 10;
				} while (num > 0);

				for (i = len - 1; i >= 0; i--)
					write(STDERR_FILENO, &buffer[i], 1);

				count += len;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				while (*str)
				{
					write(STDERR_FILENO, str, 1);
					str++;
					count++;
				}
			}
			else if (*format == 'c')
			{
				c = (char)va_arg(args, int);
				write(STDERR_FILENO, &c, 1);
				count++;
			}
		}
		else
		{
			write(STDERR_FILENO, format, 1);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
