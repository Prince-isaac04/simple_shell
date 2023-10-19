#include "shell.h"

/**
 * is_builtin - Checks if parsed command in built-in
 * @cmnd: Parsed command to be check
 * Return: 0 Succes -1 Fail
 */
int is_builtin(char **cmnd)
{
	builtin funs[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i;
	
	i = 0;

	if (*cmnd == NULL)
	{
		return (-1);
	}
	while ((funs + i)->command)
	{
		if (_strcmp(cmnd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * handle_builtins - Handles predefined built in commands
 * @cmndder: Array of parsed command strings
 * @str: Status of last execution
 * Return: -1 Failure 0 Success
 */
int handle_builtins(char **cmndder, int str)
{
	builtin built [] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_helper},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((built + i)->command)
	{
		if (_strcmp(cmndder[0], (built + i)->command) == 0)
		{
			return ((built + i)->function(cmndder, str));
		}
		i++;
	}
	return (-1);
}

/**
 * exit_bus - Exit Status for built-in commands
 * @cmndder: Array of parsed command strings
 * @inp: Input recieved from user (to be freed)
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @z: Shell execution count
 * @stat: Exit status
 */
void exit_bus(char **cmndder, char *inp, char **argv, int z, int stat)
{
	int sta, i = 0;

	if (cmndder[1] == NULL)
	{
		free(inp);
		free(cmndder);
		exit(stat);
	}
	while (cmndder[1][i])
	{
		if (_isalpha(cmndder[1][i++]) != 0)
		{
			_prerror(argv, z, cmndder);
			free(inp);
			free(cmndder);
			exit(2);
		}
		else
		{
			sta = _atoi(cmndder[1]);
			if (sta == 2)
			{
				_prerror(argv, z, cmndder);
				free(inp);
				free(cmndder);
				exit(sta;
			}
			free(inp);
			free(cmndder);
			exit(sta);

		}
	}
}
