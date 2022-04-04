/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_array_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:28:27 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/04 23:14:43 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Get length of 2d char array
int	char_array_len(char **arr)
{
	int	length;

	length = 0;
	while (arr[length])
		length++;
	return (length);
}
