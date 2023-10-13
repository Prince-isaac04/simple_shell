#include "shell.h"

/**
* token_instruction - Tokenizes and executes a specified instruction using fork and execvp
* @tokener: Pointer to the string to be tokenized and executed
* This function tokenizes the specified instruction and creates a child process to
* execute it using the execvp system call. It waits for the child process to complete
* before returning.
* Return: None
*/

void token_instruction(char *tokener)
{
        char *instruction = "ls";

    pid_t child_pid; /*pid used to track function. fork function is used to call child process it create duplicate of call function*/

    child_pid = fork ();

    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0)
    {
	    char *imput[26];
	    int char_counter;
	    const char *delimater = " ";

	   tokener = strtok((char *)instruction, delimater);
	   while (tokener != NULL)
	   {
		   imput[char_counter++] = tokener;
		   tokener = strtok(NULL, delimater);
	   }
	   imput[char_counter] = NULL;
    execvp(imput[0], imput);
print_file("error in command exec");
exit(EXIT_FAILURE);
    }
    else
    {
	    wait(NULL);
    }
}
