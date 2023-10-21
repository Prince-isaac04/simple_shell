#ifndef SHELL_H
#define SHELL_H

/***** MACROS *****/
#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFSIZE 10240
#define DELIMITER " \t\r\n\a"

/*** STANDARD LIBRARIES ***/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/******** STRING HANDLER FUNCTIONS **********/

char *_strncpy(char *de, char *sor, int y);
int _strlen(char *m);
int _putchar(char f);
int _atoi(char *f);
void _puts(char *sth);
int _strcmp(char *str1, char *str2);
int _isalpha(int z);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int z);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *z, char a);
int _strncmp(const char *str1, const char *str2, size_t z);
char *_strdup(char *str);

/*********** MEMORY HANDLERS ***********/

void free_env(char **env);
void *put_array(void *l, int y, unsigned int ln);
char *_memocpyes(char *d, char *srv, unsigned int m);
void *_calloces(unsigned int siz);
void *_realloces(void *pt, unsigned int b4_size, unsigned int nex_size);
void all_freess(char **cmny, char *lin);

/****** MISCELLANEOUS AND INPUT FUNCTIONS *******/

char *_getlin();
char *spacess(char *strm);
char *insert(char *strn);
void hashtag_hands(char *buffar);
void prompt(void);
unsigned int is_delim(char c, const char *str);
char *_strtok(char *str1, const char *delim);
int histor(char *uinput);
char **tokener(char *uinput);

/****** FILE ARGUMENT HANDLER FUNCTIONS ******/

void file_red(char *fi, char **argv);
void file_treaters(char *lin, int cou, FILE *lp, char **argv);
void leave_file_handle(char **cmn, char *lin, FILE *ld);

/****** PARSED ARGUMENT HANDLER FUNCTIONS *****/

char **par_cmd(char *input);
int handle_builtin(char **cmd, int er);
int check_cmd(char **cmd, char *userinput, int a, char **argv);
void signal_to_handle(int signal);

/******* ERROR HANDLERS ******/

void paste_error(char *uinput, int cou, char **argv);
void _pas_rerror(char **argv, int s, char **cmn);
void error_doc(char **argv, int s);

/****** ENVIRONMENT HANDLERS ******/

extern char **environ;
void en_creation(char **envir);
void en_free(char **envir);

/****** PRINTING FUNCTIONS *****/

void disp_number(unsigned int g);
void displ_number_int(int y);
int echo_printer_pro(char **cmns);

/******* PATH FINDER *******/

int path_cmnd(char **cmnd);
char *builder(char *tok, char *value);
char *_getenv(char *name);

/******* HELP HANDLERS *******/

void envro_helper(void);
void setenvro_helper(void);
void unsetenvro_helper(void);
void help_history(void);
void all_asit(void);
void alias_asit(void);
void cd_asit(void);
void exit_asit(void);
void help_asit(void);
int displayenvro_helper(char **cmnd, __attribute__((unused))int st);

/****** BUILTIN COMMAND HANDLERS AND EXECUTE ******/

int is_builtis(char **cmnd);
int han_builtis(char **cmd, int st);
void leave_bul(char **cmnd, char *input, char **argv, int z, int stat);
int change_dirt(char **cmnd, __attribute__((unused))int st);
int enve_disp(__attribute__((unused)) char **cnd,
	    __attribute__((unused)) int st);
int see_bul(char **cmnd, int st);
int hist_dis(__attribute__((unused))char **a, __attribute__((unused)) int st);

/****** BUILT-IN COMMANDS STRUCT *****/

/**
 * struct _builtin - Defines a struct that conatins built-in commands
 * with their respective implementation functions
 * @command: - Built-in command
 * @function: - Pointer to custom functions that have
 * similar functionalities as the built-in commands
 */
typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

#endif /*HEADER_H*/
