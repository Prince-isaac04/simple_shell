#include "shell.h"

/**
 * main - Entry point to program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Returns condition
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *uinput, **cmd, **commands;
	int count = 0, i, condition = 1, stat = 0;

	if (argv[1] != NULL)
		file_read(argv[1], argv);
	signal(SIGINT, signa_to_handles);
	while (condition)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prompt();
		uinput = _getline();
		if (uinput[0] == '\0')
			continue;
		histor(usinput);
		commands = tokener(uinput);
		for (i = 0; commands[i] != NULL; i++)
		{
			cmd = parse_cmdss(commands[i]);
			if (_strcmp(cmd[0], "exit") == 0)
			{
				free(commands);
				exit_bul(cmd, uinput, argv, count, stat);
			}
			else if (is_builtin(cmd) == 0)
			{
				stat = handle_builtin(cmd, stat);
				free(cmd);
				continue;
			}
			else
				stat = check_cmd(cmd, uinput, count, argv);
			free(cmd);
		}
		free(uinput);
		free(commands);
		wait(&stat);
	}
	return (stat);
}
