#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

char *pathExist(const char *ecmd);

char *string_concat(char *destination, char *root);

#endif

