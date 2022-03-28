/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:58:10 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/28 21:17:43 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

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
		lexer(data, line);
		free(line);
		parser(data);
		if (data->clean_input)
		{
			ft_lstiter(data->clean_input, ft_print);
			ft_lstclear(&data->clean_input, free);
		}
	}
	return (0);
}
