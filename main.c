#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * main- main function
 * @void: no argumrntys
 * Return: integer
 */
int main(void)
{
	size_t bytes_getline = 0;
	char *tokenized = NULL;
	size_t cmd_buf_size = 0;
	char *cmd_entered = NULL;
	int j = 0;
	int terminal_interact = 1;
	char **arguments;

	while (1)
	{
		terminal_interact = isatty(STDIN_FILENO);
		arguments = malloc(10 * sizeof(char *));

		if (terminal_interact != 0)
			our_display_prompt();
		j = 0;
		bytes_getline = getline(&cmd_entered, &cmd_buf_size, stdin);
		tokenized = strtok(cmd_entered, " \t\r\n");
		while (tokenized != NULL)
		{
			arguments[j] = malloc(sizeof(char) * strlen(tokenized) + 1);
			strcpy(arguments[j], tokenized);
			j++;
			tokenized = strtok(NULL, " \t\r\n");
		}
		if (j == 0)
		{
			free(arguments);
			continue;
		}
		arguments[j] = NULL;
		if (strcmp(arguments[0],  "exit") == 0)
		{
			memory_free(arguments);
			break;
		}
		if (terminal_interact == 0)
			break;
		if (bytes_getline > 1)
		{
			if (arguments[0] != NULL)
			{
				memory_free(arguments);
			}
		}
	}
	if (cmd_entered != NULL)
	{
		free(cmd_entered);
	}
	return (1);
}
