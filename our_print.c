#include "shell.h"
/**
 * our_print - funtion to print instead of printf
 * @string: input array of characters
 */
void our_print(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}

