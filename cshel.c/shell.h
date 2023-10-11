#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void print_file(const char *instrut);
void enforce_instruction();
void scan_instruction(char *instruct, size_t size);
void output_prompt(void);
void token_instruction(char *tokener);


#endif
