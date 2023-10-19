#include "shell.h"

/**
 * print_errors - Displays error message
 * @uinput: Input recieved from user
 * @count: Count of shell loop
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 */

void print_error(int count, char *uinput, char **argv)
{
char *pev;

	PRINT(argv[0]);
	PRINT(": ");
	per = _itoa(count);
	PRINT(pev);
	free(pev);
	PRINT(": ");
	PRINT(uinput);
	PRINT(": not found\n");
}

/**
 * error_files - Prints custom Error
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @z: Error Count
 */
void error_files(int z, char **argv)
{
	char *ve = _itoa(z);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(ve);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(ve);
}


/**
 *  _prerror - Prints custom Error
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @z: Error Count
 * @cmnd: Array of parsed command strings
 */

void _prerrors(int z, char **cmnd, char **argv)
{
	char *ve = _itoa(z);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(ve);
	PRINT(": ");
	PRINT(cmnder[0]);
	PRINT(": Illegal number: ");
	PRINT(cmnder[1]);
	PRINT("\n");
	free(ve);
}
