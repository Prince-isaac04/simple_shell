#include "shell.h"

/**
 * see_cmd - Excutes commands found in predefined path
 * @cmd: Array of parsed command strings
 * @uinput: Input recieved from user (to be freed)
 * @a:Shell Excution Time Case of Command Not Found
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int see_cmd(char **argv, char **cmd, char *uinput, int a)
{
	int sws;
	pid_t pid;

	if (*cmd == NULL)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			path_cmnd(cmd);
		if (access(cmd[0], R_OK) != 0)
		{
			print_error(cmd[0], a, argv);
			all_freed(cmd, uinput);
			exit(127);
		}
		if (execve(*cmd, cmd, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&sws);
	if (WIFEXITED(sws))
	{
		if (WEXITSTATUS(ws) == 0)
			return (0);
		else if (WEXITSTATUS(sws) == 2)
			return (2);
		else if (WEXITSTATUS(sws) == 127)
			return (127);
	}
	return (127);
}

/**
 * signal_to_handles - Configures ^C not to terminate our shell
 * @signal: Incoming Signal
 */
void signa_to_handles(int signa)
{
	if (signa == SIGINT)
	{
		PRINT("\n$ ");
	}
}
