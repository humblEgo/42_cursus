/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:18:45 by iwoo              #+#    #+#             */
/*   Updated: 2020/06/24 21:40:56 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

#define clear() printf("\033[H\033[J")

void	print_dir()
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd)); //get file path
	printf("\nDir: %s", cwd);
}

int	take_input(char *str)
{
	char *buf;

	clear();
	buf = readline("\niwoo_shell>>> ");
	if (strlen(buf) != 0)
	{
		add_history(buf);			// TODO: check what is this.
		strcpy(str, buf);
		return (0);
	}
	else
		return (1);
}

// function for finding pipe
int	parse_pipe(char *str, char **str_piped)
{
	int i;

	for (i = 0; i < 2; i++)
	{
		str_piped[i] = strsep(&str, "|");
		if (str_piped[i] == NULL)
			break;
	}
	if (str_piped[1] == NULL)
		return (0);								// returns zero if no pipe is found
	else
		return (1);
}

// function for parsing command words
void	parse_space(char *str, char **parsed)
{
	int i;

	for (i = 0; i < MAXLIST; i++)
	{
		parsed[i] = strsep(&str, " ");

		if (parsed[i] == NULL)
			break;
		if (strlen(parsed[i]) == 0)
			i--;
	}
}

int	own_cmd_handler(char **parsed)
{
	int no_of_won_cmds = 4;
	int i;
	int switch_own_arg = 0;
	char *list_of_own_cmds[no_of_own_cmds];
	char *username;


	return (0);
}

int	process_string(char *str, char **parsed, char **parsed_pipe)
{
	char	*str_piped[2];
	int		piped = 0;

	piped = parse_pipe(str, str_piped);   //is there pipe?

	if (piped)
	{
		parse_space(str_piped[0], parsed);
		parse_space(str_piped[1], parsed_pipe);
	}
	else
		parse_space(str, parsed);

	if (own_cmd_handler(parsed))
		return (0);
	else
		return (1 + piped);
}

int	main(int argc, char *argv[], char **envp)
{
	char input_string[MAXCOM];
	char *parsed_args[MAXLIST];
	char *parsed_args_piped[MAXLIST];
	int exec_flag = 0;

	while (1) {
		print_dir();
		if (take_input(input_string))
			return (0);
		//process
		exec_flag = process_string(input_string, parsed_args, parsed_args_piped);

		//execute
		if (exec_flag == 1)
			exec_args(parsed_args);
		if (exec_flag == 2)
			exec_args_piped(parsed_args, parsed_args_piped);
	}
	return (0);
}
