/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:51:05 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/06 17:52:57 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Dup2 fd_from to fd_to and close fd_from
// Check to make sure fd_from isn't standard fd (0, 1, 2)
void	dup2_and_close(int fd_from, int fd_to)
{
	if (fd_from > 2)
	{
		dup2(fd_from, fd_to);
		close(fd_from);
	}
}
