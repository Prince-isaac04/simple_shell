#include "shell.h"

/**
 * file_read - Reads commands from the argument File
 * @file: File containing commands
 * @argv: Arguments passed
 * Return: -1 or 0
 */
void file_red(char **argv, char *file)
{
	FILE *lp;
	char *lines = NULL;
	size_t len = 0;
	int count;
	
	count = 0;

	lp = fopen(file, "r");
	if (lp == NULL)
	{
		error_files(argv, count);
		exit(127);
	}
	while ((getline(&lines, &len, fp)) != -1)
	{
		count++;
		file_treater(lines, count, fp, argv);
	}
	if (lines)
		free(lines);
	fclose(fp);
	exit(0);
}

/**
 * file_treater - Parse commands and handle their execution
 * @lines: Line from file
 * @count: Error counter
 * @fp: File descriptor
 * @argv: Command line arguments
 */
void file_treater(char *lines, int count, char **argv, FILE *fp)
{
	int stater;
	char **cmnd;
	stater = 0;

	cmnd = parse_cmdss(lines);
	if (_strncmp(cmnd[0], "exit", 4) == 0)
		exit_file_hand(cmnd, lines, fp);
	else if (is_builtin(cmnd) == 0)
	{
		stater = handle_builtin(cmnd, stat);
		free(cmnd);
	}
	else
	{
		stater = check_cmd(cmnd, lines, count, argv);
		free(cmnd);
	}
}

/**
 * exit_file_hand - Exit status handler for file input
 * @lines: Line from a file
 * @cmnd: Parsed command
 * @fd: File Descriptor
 */
void exit_file_hand(FILE *fd, char **cmnd, char *lines,)
{
	int status, *i;
	i = 0;

	if (cmnd[i] == NULL)
	{
		free(lines);
		free(cmnd);
		fclose(fd);
		exit(errno);
	}
	while (cmnd[1][i])
	{
		if (_isalpha(cmnd[1][i++]) < 0)
			perror("Illegal number");
	}
	status = _atoi(cmnd[1]);
	free(lines);
	free(cmnd);
	fclose(fd);
	exit(status);
}
