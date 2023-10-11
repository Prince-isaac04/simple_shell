#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>



void _put(char *c);

/*get environ*/

char *get_path(char *path);

char *path_present(const char *ecmd);

/*string function*/

int Cal_Str_Len(const char *m);

void _strcat(char *dest, const char *src);

int strn_cmp(const char *str1, const char *str2, size_t m);

char *string_concat(char *destination, const char *root);

void copStr(char *det, const char *sor);

char *path_present(const char *ecmd);

char* dup_string(const char* input);

#endif

