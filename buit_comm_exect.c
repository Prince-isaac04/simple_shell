
#include "shell.h"

/**
 * change_dirt - Changes directory
 * @cmnd: Parsed command
 * @st: Status of last command executed
 * Return: 0 on success 1 if failed (For OLDPWD Always 0 incase of no OLDPWD)
 */
int change_dirt(char **cmnds, __attribute__((unused))int str)
{
	int vals = -1;
	char cwdz[PATH_MAX];

	if (cmnds[1] == NULL)
		vals = chdir(getenv("HOME"));
	else if (_strcmp(cmnds[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		vals = chdir(cmnd[1]);

	if (vals == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (vals != -1)
	{
		getcwd(cwdz, sizeof(cwdz));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwdz, 1);
	}
	return (0);
}

/**
 * dis_env - Display enviroment variable
 * @cnd: parsed command
 * @st: status of last command executed
 * Return: Always 0
 */
int dis_envs(__attribute__((unused)) char **cnd, __attribute__((unused)) int st)
{
	size_t is;
	int lengs;

	for (is = 0; environ[is] != NULL; is++)
	{
		lengs = _strlen(environ[is]);
		write(1, environ[is], lengs);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * echo_buls - execute echo cases
 * @st: statue of last command executed
 * @cmnd: parsed command
 * Return: Always 1 Or execute normal echo
 */
int echo_buls(char **cmndss, int str)
{
	char *pathes;
	unsigned int pid = getppid();

	if (_strncmp(cmndss[1], "$?", 2) == 0)
	{
		print_number_int(str);
		PRINT("\n");
	}
	else if (_strncmp(cmndss[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINT("\n");
	}
	else if (_strncmp(cmndss[1], "$PATH", 5) == 0)
	{
		pathes = _getenv("PATH");
		PRINT(path);
		PRINT("\n");
		free(path);
	}
	else
		return (echo_printer(cmndss));

	return (1);
}

/**
 * history_disp - display history of user input on simple_shell
 * @a: parsed command
 * @st: status of last command executed
 * Return: 0 success or -1 if fail
 */
int history_disp(__attribute__((unused))char **a, __attribute__((unused))int st)
{
	char *filenam = ".simple_shell_history", *fstlines = NULL;
	FILE *fps;
	char 
	size_t len = 0;
	int counter = 0;
	char *ps;

	fps = fopen(filename, "r");
	if (fps == NULL)
	{
		return (-1);
	}
	while ((getline(&fstlines, &len, fps)) != -1)
	{
		counter++;
		ps = _itoa(counter);
		PRINT(ps);
		free(ps);
		PRINT(" ");
		PRINT(fstlines);
	}
	if (fstlines)
		free(fstlines);
	fclose(fp);
	return (0);
}

