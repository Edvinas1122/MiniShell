/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:37:41 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/06 14:09:00 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../minishell.h"

typedef struct s_command	t_command;

/* Struct for pipes, pipe shift informs rotation position */
typedef struct s_exec_data
{
	int	pipe1[2];
	int	pipe2[2];
	int	pipe_shift;
}				t_exec_data;

/* Struct for execution execve() */
typedef struct s_exec_cmd
{
	char	**cmd_arr;
	char	*path_cmd;
}				t_exec_cmd;

void		executor(t_data *data);
/* Executor's call */
int			fork_process(t_exec_data *exec_data, char **cmd_arr,
				char **paths);
/* Fork's calls */
t_exec_cmd	accessor_con(char **cmd_arr, char **paths);
void		dup_pipe(t_exec_data *exec_data);

#endif
