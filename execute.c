#include "main.h"

#define BUFFER_SIZE 256
/**
 * print_error - Prints an error message for a command execution failure.
 * @program_name: The name of the shell program.
 * @command_count: The number of the command being executed.
 * @command: The command that failed to execute.
 */
static void print_error(const char *program_name,
		int command_count, const char *command)
{
	char buffer[BUFFER_SIZE];
	int len = 0;

	len += my_sprintf(buffer + len, "%s: %d: %s: %s\n",
			program_name, command_count, command, "not found");
	write(STDERR_FILENO, buffer, len);
}

/**
 * execute - Forks a process to execute a command using execve.
 * @command: The command to execute.
 * @command_count: The number of the command being executed.
 */
void execute(char *command, int command_count)
{
	pid_t id;
	char *argv[2];
	int status;

	argv[0] = command;
	argv[1] = NULL;

	id = fork();
	if (id == 0)
	{
		if (execve(command, argv, NULL) == -1)
		{
			print_error("./hsh", command_count, command);
			_exit(EXIT_FAILURE);
		}
	}
	else if (id > 0)
	{
		wait(&status);
	}
	else
	{
		print_error("./hsh", command_count, command);
	}
}
