#include "shell.h"

/**
 * is_builtis - Checks if parsed command in built-in
 * @cmn: Parsed command to be check
 * Return: 0 Succes -1 Fail
 */
int is_builtis(char **cmn)
{
	builtin ful[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int s = 0;

	if (*cmn == NULL)
	{
		return (-1);
	}
	while ((ful + s)->command)
	{
		if (_strcmp(cmn[0], (ful + s)->command) == 0)
			return (0);
		s++;
	}
	return (-1);
}

/**
 * han_builtis - Handles predefined built in commands
 * @cmn: Array of parsed command strings
 * @sts: Status of last execution
 * Return: -1 Failure 0 Success
 */
int han_builtis(char **cmn, int sts)
{
	builtin built_is[] = {
		{"cd", change_dirt},
		{"env", enve_disp},
		{"help", displayenvro_helper},
		{"echo", see_bul},
		{"history", hist_dis},
		{NULL, NULL}
	};
	int s = 0;

	while ((built_is + s)->command)
	{
		if (_strcmp(cmn[0], (built_is + s)->command) == 0)
		{
			return ((built_is + s)->function(cmn, sts));
		}
		s++;
	}
	return (-1);
}

/**
 * leave_bul - Exit Status for built-in commands
 * @cmn: Array of parsed command strings
 * @uput: Input recieved from user (to be freed)
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @s: Shell execution count
 * @sta: Exit status
 */
void leave_bul(char **cmn, char *uput, char **argv, int s, int sta)
{
	int statuss, v = 0;

	if (cmn[1] == NULL)
	{
		free(uput);
		free(cmn);
		exit(sta);
	}
	while (cmn[1][v])
	{
		if (_isalpha(cmn[1][v++]) != 0)
		{
			_pas_rerror(argv, s, cmn);
			free(uput);
			free(cmn);
			exit(2);
		}
		else
		{
			statuss = _atoi(cmn[1]);
			if (statuss == 2)
			{
				_pas_rerror(argv, s, cmn);
				free(uput);
				free(cmn);
				exit(statuss);
			}
			free(uput);
			free(cmn);
			exit(statuss);

		}
	}
}
