#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - Prints a sentence
 * @argc: Prints the number of arguments
 * @argv: Reads the arguments themselves
 * Description: Outputs a greeting message to the screen
 *
 * Return: Always 0 (success)
 */
int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Hello %s %s\n", argv[1], argv[2]);

		return (1);
	}

	printf("Hello %s %s\n", argv[1], argv[2]);

	return (0);
}
