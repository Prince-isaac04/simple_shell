#include "shell.h"

void tokener (char *buff, char *delim)
{
	int i, *con_tokens;
	char *token;

	while(buff[i] != "/0", && delim[i] != "/0")
	{
		i++;
	}
	token = strtok(buff, delim);

	while (token != NULL)
	{
		con_tokens++;
		token = strtok(NULL, delim);
	}
	con_tokens++;
}
	/* Allocate space to hold the array of strings */
	/*argv = malloc(sizeof(char *) * con_tokens);

	 Store each token in the argv array 
	token = strtok(buff_mem, delim);
	for (i = 0; token != NULL; i++){
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, delim);*/

