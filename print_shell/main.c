#include "shell.h"

int main(int ac, char **argv)
{   

    char *buff = NULL; /*buff_mem[6000] = {'\0'};*/
    size_t n = 0;
    ssize_t user_input;
    const char *delim = " \n";
    int con_tokens = 0;
    char *token;
    int i;

    (void)ac;
    while (1) 
    {
        write(1, "$ ", 2);
        user_input = getline(&buff, &n, stdin);
        if (user_input == -1)
	{
	    free(buff);
	    break;
        }
	if (strcmp(buff, "\n") == 0)
	{
		continue;
	}
        /*buff_mem = malloc(sizeof(char) * (user_input + 1));*/
        /*if (buff_mem== NULL){
            perror("tsh: memory allocation error");
	    exit(EXIT_FAILURE);
        }*/
        /*strcpy(buff_mem, buff);*/
        token = strtok(buff, delim);
        while (token != NULL){
            con_tokens++;
            token = strtok(NULL, delim);
        }
        con_tokens++;
        argv = malloc(sizeof(char *) * con_tokens + 1);
        token = strtok(buff, delim);
	   for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);
            token = strtok(NULL, delim);
        }
        argv[i] = NULL;
        execmd(argv);
	i = 0;
	while(argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
    }
    /*free(buff_mem);*/
    /*free(buff);*/
    return (0);
}

