/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:06:19 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/11 21:43:03 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Return the list that has content matches to_find string
// Return NULL if couldn't find
t_list	*find_list(t_list *list, char *to_find, int exact_str)
{
	while (list)
	{
		if (!ft_strncmp((char *)list->content, to_find,
				ft_strlen(to_find) + (exact_str & 1)))
			break ;
		list = list->next;
	}
	return (list);
}
