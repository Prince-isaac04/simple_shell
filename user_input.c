#include "shell.h"

/**
* scan_instruction - Reads an instruction from standard input
* @instruct: Pointer to a buffer where the instruction will be stored
* @size: Maximum number of characters to read, including the null-terminator
* This function reads an instruction from standard input using fgets. If the
* operation is successful, it removes the newline character and null-terminates
* the string. If an error occurs, it prints an error message and exits.
* Return: None
*/

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
