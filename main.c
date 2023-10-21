#include "shell.h"

/**
 *  * main - Entry point to program
 *   * @argc: Argument count
 *    * @argv: Argument vector
 *     * Return: Returns condition
 *      */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *userinput, **cmd, **commands;
	int count = 0, i, condition = 1, stat = 0;

	if (argv[1] != NULL)
		file_red(argv[1], argv);
	signal(SIGINT, signal_to_handle);
	while (condition)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prompt();
		userinput = _getlin();
		if (userinput[0] == '\0')
			continue;
		histor(userinput);
		commands = tokener(userinput);
		for (i = 0; commands[i] != NULL; i++)
		{
			cmd = par_cmd(commands[i]);
			if (_strcmp(cmd[0], "exit") == 0)
			{
				free(commands);
				leave_bul(cmd, userinput, argv, count, stat);
			}
			else if (is_builtis(cmd) == 0)
			{
				stat = han_builtis(cmd, stat);
				free(cmd);
				continue;
			}
			else
				stat = check_cmd(cmd, userinput, count, argv);
			free(cmd);
		}
		free(userinput);
		free(commands);
		wait(&stat);
	}
	return (stat);
}
