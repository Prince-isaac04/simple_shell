#include "shell.h"
extern char **environ;
int main() 
{
	char *buff = NULL, *argv[2];
	size_t n = 0;
	ssize_t eofnum;
	int errorCount = 1;
	char *cmd;
	pid_t child_pid;

	while (1) {
		write(1, "prince_tech$ ", Cal_Str_Len("prince_tech$ "));
		eofnum = getline(&buff, &n, stdin);
		if (eofnum == -1) 
		{
			free(buff);
			exit(EXIT_FAILURE);
		}

		/* Remove the newline character from the end of the input*/
		buff[eofnum - 1] = '\0';

		child_pid = fork();

		if (child_pid < 0) {
			free(buff);
			exit(EXIT_FAILURE);
		} else if (child_pid == 0) 
		{
			char *ecmd[100];  /* Adjust the array size as needed*/
			int count = 0;

			/* Tokenize the input command*/
			char *token = strtok(buff, " ");
			while (token != NULL) {
				ecmd[count++] = token;
				token = strtok(NULL, " ");
			}
			ecmd[count] = NULL;  /*Set the last element to NULL*/

			/*Execute the command using execve*/
			cmd = path_present(ecmd[0]);  /*You need to implement path_present() to find the command path*/
			if (execve(cmd, ecmd, environ) == -1) 
			{
				perror(execve);
				exit(EXIT_FAILURE);
			}
			else
			{
			_put("Unknown Program: %d: %s: not found\n", errorCount, ecmd[0]);
			}
		} 
		else 
		{
			wait(NULL);
			errorCount++;
		}
	}

	free(buff);
	return 0;
}
