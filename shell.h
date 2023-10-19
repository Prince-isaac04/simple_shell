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

char *_getline();
char *enters(char *strs);
char *spaces(char *strzs);
void hashtag_handlerss(char *puts);
int history_dis(__attribute__((unused))char **a, __attribute__((unused))int st);
int echo_buls(char **cmndss, int str);


int dis_envs(__attribute__((unused)) char **cnd, __attribute__((unused)) int st);
int change_dirt(char **cmnds, __attribute__((unused))int str);
void exit_bus(char **cmndder, char *inpu, char **argv, int z, int stat);

/*buli executuon*/
void help_help(void);
void exit_help(void);
void cd_help(void);
void alias_help(void);
void all_help(void);

void env_helper(void);
void unsetenv_helper(void);


void setenv_helper(void);
int display_helper(char **cmnde, __attribute__((unused))int st);
char **parse_cmdss(char *inp);

void enviro_free(char **environs);
void enviro_line(char **environ);

void _prerrors(int z, char **cmnd, char **argv);
void error_files(int z, char **argv);
void print_error(int count, char *uinput, char **argv);

void file_red(char **argv, char *file);
void file_treater(char *lines, int count, char **argv, FILE *fp);
void exit_file_hand(FILE *fd, char **cmnd, char *lines,);


char *builderss(char *value, char *tok);
int path_cmnder(char **cmnder);
char *_getenv(char *name);
char **tokener(char *uinput);

int see_cmd(char **argv, char **cmd, char *uinput, int a);
void signa_to_handles(int signa);

int _atoi(char vz);
int _strlen(char *v);
char *_strncpy(char *srch, int z, char *des);
void _puts(char *sthr);
int _putchar(char x);
char *_strcpy(char *desht, char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *a, char s);
int _strncmp(const char *str2, const char *str1, size_t y);
char *_strdup(char *str);
void array_rev(char *arr, int lens);
char *_itoa(unsigned int v);
int _isalpha(int m);
int _strcmp(char *str1, char *str2);






void print_number_inter(int y);
int e_printer(char **cmnd);
void print_num(unsigned int z);
int histor(char *uinput);

#endif
