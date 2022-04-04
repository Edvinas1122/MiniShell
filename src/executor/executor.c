/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:37:38 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/04 17:22:45 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/* Initiates pipe and informs the rotator */
static void	initiate_pipe(t_exec_data *exec_data)
{
	else if (exec_data->pipe_shift == 0)
	{
		pipe(exec_data->pipe1);
		exec_data->pipe_shift = 1;
	}
	else
	{
		pipe(exec_data->pipe2);
		exec_data->pipe_shift = 0;
	}
}

/* Sets input fd /is called only when first command/ */
static void	set_in_fd(t_exec_data *exec_data, int fd)
{
	exec_data->pipe2[0] = fd;
}

/* Sets output fd /is called only when last command/ */
static void	set_out_fd(t_exec_data *exec_data, int fd)
{
	if (exec_data->pipe_shift == 0)
		exec_data->pipe2[1] = fd;
	else
		exec_data->pipe1[1] = fd;
}

/* Executor, executes commands in cmd_arr. It uses pipe_shift for 
	"rotation" mechanics of piper.
	It calls fork object
	*/
void	executor(t_command command)
{
	t_exec_data	exec_data;
	t_list		*current_command;

	exec_data.pipe_shift = 1;
	current_command = *command.commands;
	set_in_fd(&exec_data, command.input_fd);
	while (1)
	{
		if (current_command->next != NULL)
			initiate_pipe(&exec_data);
		else
			set_out_fd(&exec_data, command.input_fd);
		fork_process(&exec_data, current_command->content, command.paths);
		if (current_command->next == NULL)
			break;
		current_command = current_command->next;
	}
	// destructor
}
