/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:03:45 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/06 14:10:40 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	dup_case_l(t_exec_data *exec_data)
{
	if (exec_data->pipe2[0] != STDIN_FILENO)
	{
		dup2(exec_data->pipe2[0], STDIN_FILENO);
		close(exec_data->pipe2[0]);
	}
	if (exec_data->pipe1[1] != STDOUT_FILENO)
	{
		dup2(exec_data->pipe1[1], STDOUT_FILENO);
		close(exec_data->pipe1[1]);
	}
	close(exec_data->pipe1[0]);
}

static void	dup_case_r(t_exec_data *exec_data)
{
	dup2(exec_data->pipe1[0], STDIN_FILENO);
	close(exec_data->pipe1[0]);
	if (exec_data->pipe2[1] != STDOUT_FILENO)
	{
		dup2(exec_data->pipe2[1], STDOUT_FILENO);
		close(exec_data->pipe2[1]);
	}
	if (exec_data->pipe2[0] != STDIN_FILENO)
		close(exec_data->pipe2[0]);
}

/* Dups FDs in coresponding array rotation */
void	dup_pipe(t_exec_data *exec_data)
{
	if (exec_data->pipe_shift == 0)
		dup_case_r(exec_data);
	else
		dup_case_l(exec_data);
}
