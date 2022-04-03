/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_remove_char_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:48:51 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/03 19:45:41 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Return new allocated str without char at idx
// Return NULL if error
char	*str_remove_char_at(char *str, int idx)
{
	char	*new_str;
	char	*start;

	if (!str || idx < 0)
		return (NULL);
	if (idx >= (int)ft_strlen(str))
		return (str);
	new_str = ft_calloc(ft_strlen(str), sizeof(char));
	if (!new_str)
		return (NULL);
	start = new_str;
	while (*str)
	{
		if (idx == 0)
		{
			str++;
			if (!*str)
				break ;
		}
		*new_str = *str;
		str++;
		new_str++;
		idx--;
	}
	return (start);
}
