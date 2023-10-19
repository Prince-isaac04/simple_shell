#include "shell.h"
extern char **environ;
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
}
