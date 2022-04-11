/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_delete_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:15:22 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/09 18:35:14 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	find_delete_list(t_list **list, char *match, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*list_iter;

	list_iter = *list;
	while (list_iter)
	{
		if (!ft_strncmp(list_iter->content, match, ft_strlen(match)))
		{
			tmp = list_iter->next;
			ft_lstdelone(list_iter, del);
			*list = tmp;
			break ;
		}
		if (list_iter->next && !ft_strncmp(list_iter->next->content,
				match, ft_strlen(match)))
		{
			tmp = list_iter->next->next;
			ft_lstdelone(list_iter->next, del);
			list_iter->next = tmp;
			break ;
		}
		list_iter = list_iter->next;
	}
}
