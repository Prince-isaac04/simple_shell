#include "shell.h"

/**
 * all_asit - Displays all possible builtin shellby commands
 */
void all_asit(void)
{
	char *mes = "Shellby\nThese shell commands are defined internally.\n";

	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "Type 'help' to see this list.\nType 'help name' to find ";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "out more about the function 'name'.\n\n  alias   \t";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, mes, _strlen(mes));
}

/**
 * alias_asit - Displays information on the shell by builtin command 'alias'
 */
void alias_asit(void)
{
	char *mes = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "\n\talias: Prints a list of all aliases, one per line, in ";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = " the aliases name, name2, etc. one per line, in the ";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = " an alias for each NAME whose VALUE is given. If NAME ";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "is already an alias, replace its value with VALUE.\n";
	write(STDOUT_FILENO, mes, _strlen(mes));
}

/**
 * cd_asit - Displays information on the shell by builtin command 'cd'
 */
void cd_asit(void)
{
	char *mes = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "command is interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = " given, the command is interpreted as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "\tThe environment variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "after a change of directory.\n";
	write(STDOUT_FILENO, mes, _strlen(mes));
}

/**
 * exit_asit - Displays information on the shell by builtin command 'exit'
 */
void exit_asit(void)
{
	char *mes = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = " exit 0.\n";
	write(STDOUT_FILENO, mes, _strlen(mes));
}

/**
 * help_asit - Displays information on the shell by builtin command 'help'
 */
void help_asit(void)
{
	char *mes = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, mes, _strlen(mes));
	mes = "builtin command.\n";
	write(STDOUT_FILENO, mes, _strlen(mes));
}
