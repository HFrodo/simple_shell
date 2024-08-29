#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>

void execute(char *command, int  command_count);
int my_sprintf(char *buffer, const char *format, ...);

#endif
