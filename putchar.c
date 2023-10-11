#include "shell.h"

void _put(const char *format, ...) 
{
    va_list set;
    va_start(set, format);

    char buff[1024];  /*Adjust the buffer size as needed*/

    /*Use vsnprintf to format the string into a buffer*/
    int leng = vsnprintf(buff, sizeof(buff), format, set);

    if (leng >= 0) {
        write(STDOUT_FILENO, buff, leng);
    }

    va_end(set);
}
