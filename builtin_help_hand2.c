#include "shell.h"

/**
 * envro_helper - Displays information on the shell by builtin command 'env'
 */
void envro_helper(void)
{
	char *mes = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, mes, _strlen(mes));
}

/**
 * setenvro_helper - Displays information on the shell by builtin
 * command 'setenv'
 */
void setenvro_helper(void)
{
	char *mes = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, mes, _strlen(mes));
}

/**
 * unsetenvro_helper - Displays information on the shellby builtin command
 * 'unsetenv'
 */
void unsetenvro_helper(void)
{
	char *mes = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "message to stderr.\n";
	write(STDOUT_FILENO, mes, _strlen(mes));
}

/**
 * displayenvro_helper - display help for builtin commands
 * @cmn: parsed command
 * @st: Status of last command executed
 * Return: 0 Success
 */
int displayenvro_helper(char **cmn, __attribute__((unused))int st)
{
	if (!cmn[1])
		all_asit();
	else if (_strcmp(cmn[1], "alias") == 0)
		alias_asit();
	else if (_strcmp(cmn[1], "cd") == 0)
		cd_asit();
	else if (_strcmp(cmn[1], "exit") == 0)
		exit_asit();
	else if (_strcmp(cmn[1], "env") == 0)
		envro_helper();
	else if (_strcmp(cmn[1], "setenv") == 0)
		setenvro_helper();
	else if (_strcmp(cmn[1], "unsetenv") == 0)
		unsetenvro_helper();
	else if (_strcmp(cmn[1], "help") == 0)
		help_asit();
	return (0);
}
