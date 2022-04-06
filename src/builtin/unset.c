/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:10:46 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/06 17:38:04 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	execute_unset(t_data *data, char **argv)
{
	char	*to_find;
	t_list	*list;
	t_list	*tmp;

	if (argv[1])
	{
		list = *data->envp_data.envp_cp;
		to_find = ft_strjoin(argv[1], "=");
		if (!to_find)
			return (EXIT_FAILURE);
		while (list)
		{
			if (list->next && !ft_strncmp(list->next->content,
					to_find, ft_strlen(to_find)))
			{
				tmp = list->next->next;
				ft_lstdelone(list->next, free);
				list->next = tmp;
				break ;
			}
			list = list->next;
		}
		free(to_find);
	}
	return (EXIT_SUCCESS);
}
