/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:58:57 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/12 17:53:47 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*execute execve()*/
static void	execute_command(char **cmd_arr, char **paths, char **envp)
{
	t_exec_cmd	execute;

	execute = accessor_con(cmd_arr, paths);
	if (!execute.path_cmd)
	{
		ft_putstr_fd(cmd_arr[0], STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
	}
	else
	{
		execve(execute.path_cmd, execute.cmd_arr, envp);
		perror(execute.cmd_arr[0]);
	}
}

/* Dubs pipe FD, file FD, FD regarding "rotary motion" and close previous pipe*/
static void	dup_pipe(t_exec_data *exec_data)
{
	if (exec_data->pipe_shift == 0)
	{
		dup2_and_close(exec_data->pipe1[0], STDIN_FILENO);
		dup2_and_close(exec_data->pipe2[1], STDOUT_FILENO);
		if (exec_data->pipe2[0] > 2)
			close(exec_data->pipe2[0]);
	}
	else
	{
		dup2_and_close(exec_data->pipe2[0], STDIN_FILENO);
		dup2_and_close(exec_data->pipe1[1], STDOUT_FILENO);
		if (exec_data->pipe1[0] > 2)
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

static char	**list_to_array(t_list *list)
{
	char	**array;
	int		i;

	array = ft_calloc(ft_lstsize(list) + 1, sizeof(char *));
	i = 0;
	while (list)
	{
		array[i] = list->content;
		list = list->next;
		i++;
	}
	return (array);
}

/* As a child process checks access & executes command
	It calls accessor object.
	*/
int	fork_process(t_data *data, t_exec_data *exec_data,
	char **cmd_arr, char **paths)
{
	int			pid;
	int			exit_status;

	(void)data;
	handle_child_signals();
	pid = fork();
	if (pid == 0)
	{
		dup_pipe(exec_data);
		execute_command(cmd_arr, paths,
			list_to_array(*data->envp_data.envp_cp));
		exit(127);
	}
	close_pipe(exec_data);
	waitpid(pid, &exit_status, 0);
	handle_parent_signals();
	if (WIFSIGNALED(exit_status))
		return (128 + WTERMSIG(exit_status));
	return (WEXITSTATUS(exit_status));
}
