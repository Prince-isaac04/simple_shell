#include "shell.h"

/**
 * paste_error - Displays error message
 * @uinput: Input recieved from user
 * @cou: Count of shell loop
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 */

void paste_error(char *uinput, int cou, char **argv)
{
	char *pe;

	PRINT(argv[0]);
	PRINT(": ");
	pe = _itoa(cou);
	PRINT(pe);
	free(pe);
	PRINT(": ");
	PRINT(uinput);
	PRINT(": not found\n");
}

/**
 * error_doc - Prints custom Error
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @s: Error Count
 */
void error_doc(char **argv, int s)
{
	char *no = _itoa(s);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(no);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(no);
}


/**
 *  _pas_error - Prints custom Error
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @s: Error Count
 * @cmn: Array of parsed command strings
 */

void _pas_rerror(char **argv, int s, char **cmn)
{
	char *e = _itoa(s);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(e);
	PRINT(": ");
	PRINT(cmn[0]);
	PRINT(": Illegal number: ");
	PRINT(cmn[1]);
	PRINT("\n");
	free(e);
}
