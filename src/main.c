/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:46:07 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/04 23:29:54 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print(void *str)
{
	printf("%s\n", (char *)str);
}

static void	ft_print_array(void *p)
{
	char	**command;

	command = (char **)p;
	printf("\n-list-\n");
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
		parser(data, &line);
		if (*data->command.commands)
			ft_lstiter(*data->command.commands, ft_print_array);
		ft_lstclear(data->command.commands, (void (*)(void *))free_array);
	}
	deconstructor(data);
	return (0);
}
