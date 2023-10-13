#include "shell.h"

/**
* main - Entry point of the program
* This function is the entry point of the program. It repeatedly prompts the user
* for a command, reads the instruction, and enforces it using the `enforce_instruction`
* and `token_instruction` functions.
* Return: Always 0 on success
*/

int main(void)
{
    char command[12]; /*creat a space i.e a memory*/

    while (1)
    {
        output_prompt(); /*display prompt*/
        scan_instruction(command, sizeof(command));
	enforce_instruction(command);
	token_instruction(command);
    }
}
