/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:58:57 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/06 17:53:21 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*execute execve()*/
static void	execute_command(t_exec_cmd exe, char **envp)
{
	execve(exe.path_cmd, exe.cmd_arr, envp);
	perror(exe.cmd_arr[0]);
}

/* Dubs pipe FD, file FD, FD regarding "rotary motion" and close previous pipe*/
static void	dup_pipe(t_exec_data *exec_data)
{
	if (exec_data->pipe_shift == 0)
	{
		dup2_and_close(exec_data->pipe1[0], STDIN_FILENO);
		dup2_and_close(exec_data->pipe2[1], STDOUT_FILENO);
		if (exec_data->pipe2[0] != STDIN_FILENO)
			close(exec_data->pipe2[0]);
	}
	else
	{
		dup2_and_close(exec_data->pipe2[0], STDIN_FILENO);
		dup2_and_close(exec_data->pipe1[1], STDOUT_FILENO);
		if (exec_data->pipe1[0] != STDIN_FILENO)
			close(exec_data->pipe1[0]);
	}
}

/* Closes regarding "rotary motion" */
static void	close_pipe(t_exec_data *exec_data)
{
	if (exec_data->pipe_shift == 0)
	{
		if (exec_data->pipe1[0] != STDIN_FILENO)
			close(exec_data->pipe1[0]);
		if (exec_data->pipe2[1] != STDOUT_FILENO)
			close(exec_data->pipe2[1]);
	}
	else
	{
		if (exec_data->pipe2[0] != STDIN_FILENO)
			close(exec_data->pipe2[0]);
		if (exec_data->pipe1[1] != STDOUT_FILENO)
			close(exec_data->pipe1[1]);
	}
}

/* As a child process checks access & executes command
	It calls accessor object.
	*/
int	fork_process(t_data *data, t_exec_data *exec_data,
	char **cmd_arr, char **paths)
{
	int			pid;
	t_exec_cmd	execute;
	int			status;

	(void)data;
	pid = fork();
	if (pid == 0)
	{
		dup_pipe(exec_data);
		execute = accessor_con(cmd_arr, paths);
		if (!execute.path_cmd)
		{
			ft_putstr_fd(cmd_arr[0], 2);
			ft_putendl_fd(": command not found", 2);
		}
		else
			execute_command(execute, NULL);
		exit(127);
	}
	close_pipe(exec_data);
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}
