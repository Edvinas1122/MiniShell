/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chararraylen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:28:27 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/03 23:35:13 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Get length of 2d char array
int	chararraylen(char **arr)
{
	int	length;

	length = 0;
	while (arr[length])
		length++;
	return (length);
}
