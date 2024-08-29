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
void my_printf(const char *format, ...);

#endif
