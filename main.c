#include "shell.h"

#include "shell.h"
extern char **environ;
int main()
{
    char *buff = NULL;
    size_t n = 0;
    ssize_t eofnum;
    int errorCount = 1;
    char *cmd;
    char c = '\n';
    pid_t child_pid;
    char *ecmd[100]; /* Adjust the array size as needed*/
    int count = 0;

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
        if (!(strcmp(buff, "\n")))
        {
            continue;
        }

        /*================================================*/
        /* Tokenize the input command*/
        char *token = strtok(buff, " \n");
        while (token != NULL)
        {
            ecmd[count++] = token;
            token = strtok(NULL, " \n");
        }
        ecmd[count] = NULL; /*Set the last element to NULL*/

        if ((strcmp(ecmd[0], "exit")) == 0)
        {
            free(buff);
            exit(EXIT_FAILURE);
        }
        /* Remove the newline character from the end of the input*/
        buff[eofnum - 1] = '\0';

        child_pid = fork();

        if (child_pid < 0)
        {
            free(buff);
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {
            /*Execute the command using execve*/
            cmd = path_present(ecmd[0]); /*You need to implement path_present() to find the command path*/
            if (execve(cmd, ecmd, environ) == -1)
            {
                perror("Error");
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
            /*free(ecmd);*/
        }
    }

    free(buff);
    return 0;
}
