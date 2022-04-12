/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes_signal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:57:28 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/12 20:57:44 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	close_pipes_signal(t_exec_data exec_data, int exit_status)
{
	if (exit_status > 128)
	{
		if (exec_data.pipe_shift == 0)
			close(exec_data.pipe2[1]);
		else
			close(exec_data.pipe1[1]);
	}
}
