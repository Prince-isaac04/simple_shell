#include "shell.h"

char* dup_string(const char* input)
{
    size_t length = Cal_Str_Len(input);
    char* duplicateds = (char*)malloc((length + 1) * sizeof(char));

    if (duplicateds != NULL) 
    {
	    size_t i;

        for (i = 0; i < length; i++) 
	{
            duplicateds[i] = input[i];
        }
        duplicateds[length] = '\0'; 
    }
    return (duplicateds);
}
