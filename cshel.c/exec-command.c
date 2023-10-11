#include "shell.h"

void enforce_instruction()
{
	char *instruction = "ls";
        char *instruc_add[] = {"mv", "-r", NULL};

    pid_t child_pid; /*pid used to track function. fork function is used to call child process it create duplicate of call function*/

    child_pid = fork ();

    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0)
    {
        execvp(instruction, instruc_add); /* or execlp (command, command, (char *)NULL);*/
        perror("execvp");
        exit(EXIT_FAILURE);
    }
        else
        {
            wait(NULL);
        }
}
