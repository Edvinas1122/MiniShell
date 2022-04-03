/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:58:10 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/04 00:37:52 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_print(void *p)
{
	char	**command;

	command = (char **)p;
	while (*command)
	{
		printf("%s\n", *command);
		command++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	char	*line;

	(void)argc;
	(void)argv;
	data = constructor(envp);
	while (42)
	{
		line = readline("minishell> ");
		if (line == NULL)
			break ;
		add_history(line);
		if (!parser(data, &line))
			continue ;
		if (data->command.commands)
			ft_lstiter(*data->command.commands, ft_print);
	}
	deconstructor(data);
	return (0);
}
