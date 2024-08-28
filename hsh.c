#include "main.h"
#include <errno.h>

/**
 * main - implements the shell
 *
 * Description: This function displays a prompt, read user input,
 * remoces the newline character, and executes the input command
 * until an exit condition is encountered
 *
 * Return: Always 0 on success
 */

int main(void)
{
	ssize_t read;
	char *buffer = NULL;
	size_t size = 0;

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
				perror("Error reading line");
				break;
			}
		}

		if (buffer[read - 1] == '\n')
			buffer[read - 1] = '\0';

		execute(buffer);
	}

	free(buffer);

	return (0);
}
