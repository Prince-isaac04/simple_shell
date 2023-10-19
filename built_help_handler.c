#include "shell.h"

/**
 * env_helper - Displays information on the shell by builtin command 'env'
 */
void env_helper(void)
{
	char *mesger = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, mesger, _strlen(mesger));
}

/**
 * setenv_helper - Displays information on the shell by builtin
 * command 'setenv'
 */
void setenv_helper(void)
{
	char *mesger = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, mesger, _strlen(mesger));
	mesger = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, mesger, _strlen(mesger));
	mesger = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, mesger, _strlen(mesger));
}

/**
 * unsetenv_helper - Displays information on the shellby builtin command
 * 'unsetenv'
 */
void unsetenv_helper(void)
{
	char *mesger = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, mesger, _strlen(mesg));
	mesger = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, mesger, _strlen(mesg));
	mesger = "message to stderr.\n";
	write(STDOUT_FILENO, mesger, _strlen(mesg));
}

/**
 * display_helper - display help for builtin commands
 * @cmnd: parsed command
 * @st: Status of last command executed
 * Return: 0 Success
 */
int display_helper(char **cmnde, __attribute__((unused))int st)
{
	if (!cmnd[1])
		all_help();
	else if (_strcmp(cmnde[1], "alias") == 0)
		alias_help();
	else if (_strcmp(cmnde[1], "cd") == 0)
		cd_help();
	else if (_strcmp(cmnde[1], "exit") == 0)
		exit_help();
	else if (_strcmp(cmnde[1], "env") == 0)
		env_helper();
	else if (_strcmp(cmnde[1], "setenv") == 0)
		setenv_helper();
	else if (_strcmp(cmnde[1], "unsetenv") == 0)
		unsetenv_helper();
	else if (_strcmp(cmnde[1], "help") == 0)
		help_help();
	return (0);
}
