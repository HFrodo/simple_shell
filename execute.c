#include "main.h"

/**
 * execute - Executes the command in the child process.
 * @command: The input command from the command line.
 * @command_count: The count of commands executed so far.
 *
 * Description: This function creates a child process using fork().
 * The child process then attempts to execute the command using execve().
 * If execve fails, an error message is printed and the child exits.
 * The parent process waits for the child to finish.
 */
void execute(char *command, int command_count)
{
	pid_t id;
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	id = fork();

	if (id == 0)
	{
		if (execve(command, argv, NULL) == -1)
		{
			my_printf("./hsh: %d: %s: not found\n", command_count, command);
			_exit(EXIT_FAILURE);
		}
	}
	else if (id > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("Fork failed");
	}
}
