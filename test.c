#include <stdio.h>
#include <unistd.h>

/**
 * main - Prints ppid
 *
 * Description: Outputs ppid of the current process
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	pid_t my_pid;

	my_pid = getppid();

	printf("This program's ppid is: %d\n", my_pid);
	return (0);
}
