#include "shell.h"
void execmd(char **argv) {
	pid_t pid;
    char *command = NULL, *actual_command = NULL;

    if (argv) {
        /* get the command */
        command = argv[0];

        /* generate the path to this command before passing it to execve */
        actual_command = get_location(command);

        /* fork a child process to execute the command */
       pid = fork();

        if (pid == -1) {
            perror("Fork error:");
        } else if (pid == 0) {  /*Child process*/
            if (execve(actual_command, argv, NULL) == -1) {
                perror("Execve error:");
                exit(EXIT_FAILURE);
            }
        } else {  /* Parent process*/
            int status;
            waitpid(pid, &status, 0);  /*Wait for the child process to complete*/
        }
    }
}
