#include "shell.h"

void scan_instruction(char *instruct, size_t size)
{
    if (fgets(instruct, size, stdin) == NULL)
    {
        if (feof(stdin))
        {
            print_file("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            print_file("failure");
            exit(EXIT_FAILURE);
        }
    }
    instruct[strcspn(instruct, "/n")] = '\0';
}
