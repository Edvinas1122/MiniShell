/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:46:55 by emomkus           #+#    #+#             */
/*   Updated: 2022/03/18 18:45:42 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipes.h"

int	format_command(char **argv, t_command *command)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		
		command->directory = ft_calloc(sizeof(char), 14);
		
		ft_strlcpy(command->directory, "/usr/bin/wc", 14);
		command->args = ft_calloc(sizeof(char *), 2);
		command->args[0] = ft_calloc(sizeof(char), 3);
		ft_strlcpy((command->args)[0], "wc", 3);
	}
	return(i);
}

static int	count_commands(void)
{
	return (2);
}

t_command	**input_parce(int argc, char **argv, char **envp)
{
	t_command	**commands;
	int			num_of_commands;
	int			x;
	int			i;

	if (!argc || !argv || !envp)
		exit(0);
	num_of_commands = count_commands();
	commands = ft_calloc(sizeof(t_command *), argc + 1);
	x = 0;
	i = 0;
	while(i <= num_of_commands)
	{
		commands[i] = malloc(sizeof(t_command));
		x = format_command(&argv[x], commands[i]);
		i++;
	}
	
	// commands[0] = format_command(1);
	// commands[1] = format_command(2);
	return (commands);
}
