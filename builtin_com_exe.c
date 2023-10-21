#include "shell.h"

/**
 * change_dirt - Changes directory
 * @cmn: Parsed command
 * @st: Status of last command executed
 * Return: 0 on success 1 if failed (For OLDPWD Always 0 incase of no OLDPWD)
 */
int change_dirt(char **cmn, __attribute__((unused))int st)
{
	int val = -1;
	char cwd[PATH_MAX];

	if (cmn[1] == NULL)
		val = chdir(getenv("HOME"));
	else if (_strcmp(cmn[1], "-") == 0)
	{
		val = chdir(getenv("OLDPWD"));
	}
	else
		val = chdir(cmn[1]);

	if (val == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (val != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * env_dis - Display enviroment variable
 * @cnd: parsed command
 * @st: status of last command executed
 * Return: Always 0
 */
int env_dis(__attribute__((unused)) char **cnd, __attribute__((unused)) int st)
{
	size_t v;
	int le;

	for (v = 0; environ[v] != NULL; v++)
	{
		le = _strlen(environ[v]);
		write(1, environ[v], le);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * see_bul - execute echo cases
 * @sts: statue of last command executed
 * @cmn: parsed command
 * Return: Always 1 Or execute normal echo
 */
int see_bul(char **cmn, int sts)
{
	char *pah;
	unsigned int seyipid = getppid();

	if (_strncmp(cmn[1], "$?", 2) == 0)
	{
		displ_number_int(sts);
		PRINT("\n");
	}
	else if (_strncmp(cmn[1], "$$", 2) == 0)
	{
		disp_number(seyipid);
		PRINT("\n");
	}
	else if (_strncmp(cmn[1], "$PATH", 5) == 0)
	{
		pah = _getenv("PATH");
		PRINT(pah);
		PRINT("\n");
		free(pah);
	}
	else
		return (echo_printer_pro(cmn));

	return (1);
}

/**
 * hist_dis - display history of user input on simple_shell
 * @a: parsed command
 * @st: status of last command executed
 * Return: 0 success or -1 if fail
 */
int hist_dis(__attribute__((unused))char **a, __attribute__((unused))int st)
{
	char *filenam = ".simple_shell_history";
	char *pe;
	FILE *lp;
	char *fistline = NULL;
	size_t lens = 0;
	int cou = 0;

	lp = fopen(filenam, "r");
	if (lp == NULL)
	{
		return (-1);
	}
	while ((getline(&fistline, &lens, lp)) != -1)
	{
		cou++;
		pe = _itoa(cou);
		PRINT(pe);
		free(pe);
		PRINT(" ");
		PRINT(fistline);
	}
	if (fistline)
		free(fistline);
	fclose(lp);
	return (0);
}
