/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:06:19 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/03 14:35:56 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Return the list that has content matches to_find string
// Return NULL if couldn't find
t_list	*find_list(t_list *list, char *to_find)
{
	while (list)
	{
		if (!ft_strncmp((char *)list->content, to_find, ft_strlen(to_find)))
			break ;
		list = list->next;
	}
	return (list);
}
