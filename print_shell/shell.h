#ifndef SHELL_H
#define SHELL_H	
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


char *get_location(char *command);


void execmd(char **argv);

#endif
