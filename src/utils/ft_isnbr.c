/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:40:01 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/09 15:41:18 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// check if string is a valid number
int	ft_isnbr(char *nptr)
{
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	if (!*nptr)
		return (0);
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			return (0);
		nptr++;
	}
	return (1);
}
