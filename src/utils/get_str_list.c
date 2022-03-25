/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:06:19 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/28 18:07:38 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*get_str_list(t_list *list, char *to_find)
{
	while (list)
	{
		if (!ft_strncmp((char *)list->content, to_find, ft_strlen(to_find)))
			break ;
		list = list->next;
	}
	return (list);
}
