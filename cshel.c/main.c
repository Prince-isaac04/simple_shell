#include "shell.h"

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
