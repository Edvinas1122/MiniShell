/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:46:07 by emomkus           #+#    #+#             */
/*   Updated: 2022/03/22 15:55:46 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_a(void *str)
{
	printf("%s\n", (char *)str);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	char	*line;

	data = constructor(envp);
	while (42)
	{
		line = readline("minishell> ");
		if (line == NULL)
			break ;
		printf("%s\n", line);
		free(line);
	}
	// deconstructor
	//ft_lstiter(*data->envp_data.envp_cp, ft_print_a);
	return (0);
}
