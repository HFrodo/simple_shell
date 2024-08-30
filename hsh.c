#include "main.h"
#include <errno.h>

#define BUFFER_SIZE 256

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
	ssize_t read;
	char *buffer = NULL;
	size_t size = 0;
	int command_count = 1;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		read = getline(&buffer, &size, stdin);
		if (read == -1)
		{
			if (errno == 0)
			{
				break;
			}
			else
			{
				write(STDERR_FILENO, "Error reading line\n", 20);
				break;
			}
		}

		if (buffer[read - 1] == '\n')
		{
			buffer[read - 1] = '\0';
		}

		execute(buffer, command_count++);
	}

	free(buffer);
	return (0);
}
