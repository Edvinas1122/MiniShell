/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:46:07 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/03 17:05:36 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print(void *str)
{
	printf("%s\n", (char *)str);
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
		parser(data, line);
		free(line);
		if (data->clean_input)
		{
			ft_lstiter(data->clean_input, ft_print);
			ft_lstclear(&data->clean_input, free);
		}
	}
	deconstructor(data);
	return (0);
}
