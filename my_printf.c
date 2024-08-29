#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 256

/**
 * my_putchar - Writes a character to the buffer.
 * @c: The character to write.
 * @buffer: The buffer to write the character into.
 * @index: The current index in the buffer.
 */
static void my_putchar(char c, char *buffer, int *index)
{
	if (*index < BUFFER_SIZE - 1)
	{
		buffer[(*index)++] = c;
	}
}

/**
 * print_int - Converts an integer to a string and adds it to the buffer.
 * @num: The integer to convert and add.
 * @buffer: The buffer to write the integer into.
 * @index: The current index in the buffer.
 */
static void print_int(int num, char *buffer, int *index)
{
	char num_buffer[10];
	int num_index = 0;
	
	if (num < 0)
	{
		my_putchar('-', buffer, index);
		num = -num;
	}
	if (num == 0)
	{
		my_putchar('0', buffer, index);
		return;
	}
	while (num > 0)
	{
		num_buffer[num_index++] = '0' + (num % 10);
		num /= 10;
	}
	while (num_index > 0)
	{
		my_putchar(num_buffer[--num_index], buffer, index);
	}
}

/**
 * print_string - Adds a string to the buffer.
 * @str: The string to add.
 * @buffer: The buffer to write the string into.
 * @index: The current index in the buffer.
 */
static void print_string(char *str, char *buffer, int *index)
{
	while (*str)
	{
		my_putchar(*str++, buffer, index);
	}
}

/**
 * print_char - Adds a character to the buffer.
 * @c: The character to add.
 * @buffer: The buffer to write the character into.
 * @index: The current index in the buffer.
 */
static void print_char(char c, char *buffer, int *index)
{
	my_putchar(c, buffer, index);
}

/**
 * my_sprintf - Formats and stores a string into a buffer.
 * @buffer: The buffer to store the formatted string.
 * @format: The format string.
 * @...: The values to format and store.
 *
 * Return: The number of characters written.
 */
int my_sprintf(char *buffer, const char *format, ...)
{
	va_list args;
	const char *p = format;
	int index = 0;

	va_start(args, format);

	while (*p)
	{
		if (*p == '%' && *(p + 1))
		{
			p++;
			switch (*p)
			{
			case 'd':
				print_int(va_arg(args, int), buffer, &index);
				break;
			case 's':
				print_string(va_arg(args, char *), buffer, &index);
				break;
			case 'c':
				print_char((char)va_arg(args, int), buffer, &index);
				break;
			default:
				my_putchar('%', buffer, &index);
				my_putchar(*p, buffer, &index);
				break;
			}
			p++;
		}
		else
		{
			my_putchar(*p, buffer, &index);
			p++;
		}
	}

	buffer[index] = '\0';

	va_end(args);
	return (index);
}
