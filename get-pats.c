#include "shell.h"

extern char **environ;

char *get_path(char *path)
{
  char **env = environ;
  char *path_env = malloc(Cal_Str_Len(path) + 1);

  if (path_env == NULL)
    return (NULL);

  while((path_env = *(env++)) != NULL)
  {
    if (strn_cmp(path_env, path, Cal_Str_Len(path)) == 0)
    {
      return (path_env);
    }
  }
  free(path_env);
  return (NULL);

}

char *path_present(const char *ecmd)
{
  char *path = get_path("PATH="), *path_dup = NULL;
  char *path_token = NULL, *delim = ":", *fullPath = NULL;

  path_dup = dup_string(path);
  if (path_dup == NULL)
    return (NULL);

  path_token = strtok(path_dup, delim);
  while (path_token != NULL)
  {
    fullPath = malloc(Cal_Str_Len(path_token) + Cal_Str_Len(ecmd) + 3);
    if (fullPath == NULL)
      return(NULL);

    copStr(fullPath, path_token);
    
    _strcat(fullPath, "/");
    string_concat(fullPath, ecmd);
    string_concat(fullPath, "\0");

    if (access(fullPath, X_OK) == 0)
    {
      return (fullPath);
    }

    path_token = strtok(NULL, delim);

    free(fullPath);

  }
  return (NULL);
}
