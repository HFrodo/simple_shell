#include "main.h"
#include <unistd.h>

/**
 * execute - executes the command in the child process
 * @command: input command from command line
 *
 *  Description: contains the command execution logic:
 *  which creates a child process using fork();
 *  child process executes command using execve;
 *  if execve fails, error is shown;
 *  whilst the parent waits for child proc to execute.
 */

void execute(char *command)
{
	pid_t id;

	int status;

	char *argv[2];

	id = fork();

	if (id == 0)
	{
		argv[0] = command;
		argv[1] = NULL;

		if (execve(command, argv, NULL) == -1)
		{
			perror("Error");

			exit(-1);
		}
	}
	else if (id > 0)
	{
		wait(&status);
	}
	else
	{
		perror("Fork failed");
	}
}
