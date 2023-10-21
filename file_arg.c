#include "shell.h"

/**
 * file_red - Reads commands from the argument File
 * @fi: File containing commands
 * @argv: Arguments passed
 * Return: -1 or 0
 */
void file_red(char *fi, char **argv)
{
	char *lin = NULL;
	size_t l = 0;
	int cou = 0;
	FILE *lp;

	lp = fopen(fi, "r");
	if (lp == NULL)
	{
		error_doc(argv, cou);
		exit(127);
	}
	while ((getline(&lin, &l, lp)) != -1)
	{
		cou++;
		file_treaters(lin, cou, lp, argv);
	}
	if (lin)
		free(lin);
	fclose(lp);
	exit(0);
}

/**
 * file_treaters - Parse commands and handle their execution
 * @lin: Line from file
 * @cou: Error counter
 * @lp: File descriptor
 * @argv: Command line arguments
 */
void file_treaters(char *lin, int cou, FILE *lp, char **argv)
{
	int sta = 0;
	char **cmn;

	cmn = par_cmd(lin);
	if (_strncmp(cmn[0], "exit", 4) == 0)
		leave_file_handle(cmn, lin, lp);
	else if (is_builtis(cmn) == 0)
	{
		sta = han_builtis(cmn, sta);
		free(cmn);
	}
	else
	{
		sta = check_cmd(cmn, lin, cou, argv);
		free(cmn);
	}
}

/**
 * leave_file_handle - Exit status handler for file input
 * @lin: Line from a file
 * @cmn: Parsed command
 * @ld: File Descriptor
 */
void leave_file_handle(char **cmn, char *lin, FILE *ld)
{
	int sta;
	int k = 0;

	if (cmn[k] == NULL)
	{
		free(lin);
		free(cmn);
		fclose(ld);
		exit(errno);
	}
	while (cmn[1][k])
	{
		if (_isalpha(cmn[1][k++]) < 0)
			perror("Illegal number");
	}
	sta = _atoi(cmn[1]);
	free(lin);
	free(cmn);
	fclose(ld);
	exit(sta);
}
