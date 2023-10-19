#include "shell.h"

/**void alias_help(void)
 * all_help - Displays all possible builtin shellby commands
 */
void all_help(void)
{
char *mesgde = "Shellby\nThese shell commands are defined internally.\n";

	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = "Type 'help' to see this list.\nType 'help name' to find ";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = "out more about the function 'name'.\n\n  alias   \t";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
}

/**
 * alias_help - Displays information on the shell by builtin command 'alias'
 */
void alias_help(void)
{
	char *mesgde = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = "\n\talias: Prints a list of all aliases, one per line, in ";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = " the aliases name, name2, etc. one per line, in the ";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = " an alias for each NAME whose VALUE is given. If NAME ";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = "is already an alias, replace its value with VALUE.\n";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
}

/**
 * cd_help - Displays information on the shell by builtin command 'cd'
 */
void cd_help(void)
{
	char *mesgde = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = "command is interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = " given, the command is interpreted as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, mesg, _strlen(mesgde));
	mesgde = "\tThe environment variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, mesg, _strlen(mesgde));
	mesgde = "after a change of directory.\n";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
}

/**
 * exit_help - Displays information on the shell by builtin command 'exit'
 */
void exit_help(void)
{
	char *mesgde = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = " exit 0.\n";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
}

/**
 * help_help - Displays information on the shell by builtin command 'help'
 */
void help_help(void)
{
	char *mesgde = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
	mesgde = "builtin command.\n";
	write(STDOUT_FILENO, mesgde, _strlen(mesgde));
}


