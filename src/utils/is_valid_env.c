/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:12:10 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/08 19:46:14 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Check if string is a valid environment name
// Return 0 if not otherwise size of the string
int	is_valid_env(char *str)
{
	int	len;

	len = 0;
	while (str && str[len])
	{
		if ((ft_isalpha(str[len]) || ft_isdigit(str[len]) || str[len] == '_'))
		{
			if (!len && ft_isdigit(str[len]))
				return (0);
			len++;
		}
		else
			return (0);
	}
	return (len);
}
