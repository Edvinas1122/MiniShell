/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:12:10 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/08 18:23:18 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Check if string is a valid environment name
// Return 0 if not otherwise size of the string
int	is_valid_env(char *str)
{
	int	len;

	len = 0;
	if (str && (ft_isalpha(str[len]) || str[len] == '_'))
		len++;
	else
		return (0);
	while (str[len])
	{
		if ((ft_isalpha(str[len]) || ft_isdigit(str[len]) || str[len] == '_'))
			len++;
		else
			return (0);
	}
	return (len);
}
