/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:54:10 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/09 15:02:03 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	execute_env(t_data *data, char **argv)
{
	t_list	*list;

	(void)argv;
	list = *data->envp_data.envp_cp;
	while (list)
	{
		ft_putendl_fd(list->content, STDOUT_FILENO);
		list = list->next;
	}
	return (EXIT_SUCCESS);
}
