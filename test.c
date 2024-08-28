#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - Prints a sentence
 *
 * Description: Outputs a greeting message to the screen
 *
 * Return: Always 0 (success)
 */
void say_hello(char *name);
int main(int argc, char **argv)
{
	printf("Hello %s %s\n", argv[1], argv[2]);
	
	return (0);
}
/*
{
   pid_t rvalue;
	rvalue = getpid();
	
	printf("Hello, my name is David\n");
	
	printf("The PID value is: %i\n", rvalue);

	say_hello("David");

	return (0);
}

void say_hello(char *name)
{
	printf("Hello %s!\n", name);
}
*/

