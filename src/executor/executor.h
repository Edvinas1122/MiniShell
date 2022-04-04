/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:37:41 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/04 19:21:12 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EXECUTOR_H
# define EXECUTOR_H

#include "../minishell.h"

/* Struct for pipes, pipe shift informs rotation position */
typedef struct	s_exec_data
{
	int	pipe1[2];
	int pipe2[2];
	int	pipe_shift;
}				t_exec_data;

/* Struct for execution execve() */
typedef struct	s_exec_cmd
{
	char	**cmd_arr
	char	*path_cmd;
}				t_exec_cmd;

void	executor(t_command command);
void	fork_process(t_exec_data *exec_data, t_commands_min commands);
t_exec_cmd	accessor_con(void **cmd_arr, char **paths);

#endif
