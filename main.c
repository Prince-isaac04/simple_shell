#include "shell.h"

/**
 * main - Entry point of the program
 * This function is the entry point of the program. It repeatedly prompts the user
 * for a command, reads the instruction, and enforces it using the `enforce_instruction`
 * and `token_instruction` functions.
 * Return: Always 0 on success
 */
extern char **environ;
int main()
{
	/*char *argv[];*/
	char *buff = NULL;
	size_t n = 0;
	ssize_t eofnum;
	/*int errorCount = 1;*/
	char *cmd;
	char c = '\n';
	char *token;
	pid_t child_pid;
	char *ecmd[100]; /* Adjust the array size as needed*/
	int count = 0;
	/*char *argv[] = {"ls", NULL};*/


	while (1)
	{
		write(1, "prince_tech$ ", Cal_Str_Len("prince_tech$ "));
		eofnum = getline(&buff, &n, stdin);
		if (eofnum == -1)
		{
			write(1, &c, 1);
			free(buff);
			exit(EXIT_FAILURE);
		}

		if (!(_strncmps(buff, "\n")))
		{
			continue;
		}

		/*================================================*/
		/* Tokenize the input command*/
		token = strtok(buff, " \n");
		for (; token != NULL; token = strtok(NULL, " \n"), count++)
		{
			ecmd[count] = token;
		}
		ecmd[count] = NULL; /*Set the last element to NULL*/

		if ((_strncmps(ecmd[0], "exit")) == 0)
		{
			free(buff);
			exit(EXIT_FAILURE);
		}
		cmd = path_present(ecmd[0]);
		/* Remove the newline character from the end of the input*/

		child_pid = fork();

		if (child_pid < 0)
		{
			free(buff);
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)        /*Execute the command using execve*/
		{


			/*cmd = path_present(ecmd[0]);*/ /*You need to implement path_present() to find the command path*/

			/*printf("%s \n", cmd);*/

			if (execve(cmd, ecmd, NULL) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			/*else
			  {
			  write(1, "command not found", Cal_Str_Len("command mot found"));
		  }*/
		}
		else
		{
			wait(NULL);
			continue;
			/*errorCount++;*/
			/*free(ecmd);*/
		}
	}

	free(buff);
	return 0;
}
