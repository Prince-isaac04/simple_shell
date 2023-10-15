#ifndef SHELL_H
#define SHELL_H
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>


/*get environ*/

char *get_path(char *path);

char *path_present(char *ecmd);

/*string function*/

int Cal_Str_Len(const char *m);

char *_strcat(char *dest, const char *src);

int _strncmps(char *st1, char *st2);

void copStr(char *det, const char *sor);

char* dup_string(const char* input);

int _strncmp(const char *list1, const char *list2, size_t c);


#endif
