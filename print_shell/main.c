#include "shell.h"

int main(int ac, char **argv)
{    char *buff = NULL, *buff_mem = NULL;
    size_t n = 0;
    ssize_t user_input;
    const char *delim = " \n";
    int con_tokens = 0;
    char *token;
    int i;

    /* declaring void variables */
    (void)ac;

    /* Create a loop for the shell's prompt */
    while (1) 
    {
        write(1, "$ ", 2);
        user_input = getline(&buff, &n, stdin);
        /* check if the getline function failed or reached EOF or user use CTRL + D */ 
        if (user_input == -1){
            write(1, "Exiting shell....\n", 18);
	    free(buff);
	    break;
        }

        /* allocate space for a copy of the lineptr */
        buff_mem = malloc(sizeof(char) * user_input);
        if (buff_mem== NULL){
            perror("tsh: memory allocation error");
	    exit(EXIT_FAILURE);
        }
        /* copy lineptr to lineptr_copy */
        strcpy(buff_mem, buff);

        /********** split the string (lineptr) into an array of words ********/
        /* calculate the total number of tokens */
        token = strtok(buff, delim);

        while (token != NULL){
            con_tokens++;
            token = strtok(NULL, delim);
        }
        con_tokens++;

        /* Allocate space to hold the array of strings */
        argv = malloc(sizeof(char *) * con_tokens);

        /* Store each token in the argv array */
        token = strtok(buff_mem, delim);
	   for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        /* execute the command */
        execmd(argv);

    }


    /* free up allocated memory */
    free(buff_mem);
    free(buff);

    return (0);
}

