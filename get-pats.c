#include "shell.h"

/**
 * 
 * 
 * 
*/
/*extern char **environ;

char *get_path(char *path)
{
  char **env = environ;
  char *path_env = NULL;

 

  while(*env != NULL)
  {
    if (_strncmp(*env, path, Cal_Str_Len(path)) == 0)
    {
      path_env = *env;
      return (path_env);
    }
    env++;
  }

  return (NULL);
}*/




char *path_present(char *ecmd)
{
	char *path = "/bin/";
	char *str = strdup(ecmd);
	char *input = _strcat(path, str);
	/*printf("%s", iknput);*/
	return (input);
  /*char *path = get_path("PATH="), *path_dup = NULL;
  char *path_token = NULL, *delim = ":", *fullPath = NULL;

  path_dup = dup_string(path);
  if (path_dup == NULL)
    return (NULL);

  path_token = strtok(path_dup, delim);
  while (path_token != NULL)
  {
    fullPath = malloc(sizeof(char) * Cal_Str_Len(path_token) + Cal_Str_Len(ecmd) + 3);
    if (fullPath == NULL)
      return(NULL);

    copStr(fullPath, path_token);
    
    _strcat(fullPath, "/");
    _strcat(fullPath, ecmd);
    _strcat(fullPath, "\0");

    if (access(fullPath, X_OK) == 0)
    {
      return (fullPath);
    }

    path_token = strtok(NULL, delim);

    free(fullPath);

  }
  return (NULL);*/
}
