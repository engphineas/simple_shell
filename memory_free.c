#include "shell.h"
/**
 * memory_free- function to free memory
 * @arguments: keyed in argumrntys
 * Return: void
 */

void memory_free(char **arguments)
{
	int k;

	if (arguments == NULL)
		return;
	for (k = 0; arguments[k]; k++)
	{
		if (arguments[k] != NULL)
		{
			free(arguments[k]);
		}
	}
	if (arguments != NULL)
		free(arguments);
}
