/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:58:57 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/06 15:18:06 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*execute execve()*/
static void	execute_command(t_exec_cmd exe, char **envp)
{
	execve(exe.path_cmd, exe.cmd_arr, envp);
	perror(exe.cmd_arr[0]);
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

/* checks for builtins and executes them if finds
	no invalid argument check */
static void	check_or_execute_builin(t_data *data, char **cmd_arr)
{
	if (!ft_strncmp(cmd_arr[0], "echo", 5))
		execute_echo(cmd_arr);
	// else if (ft_strncmp(cmd_arr[0], "cd", 3))
	// 	execute_cd(cmd_arr);
	// else if (ft_strncmp(cmd_arr[0], "pwd", 4))
	// 	execute_pwd(cmd_arr);
	// else if (ft_strncmp(cmd_arr[0], "export", 7))
	// 	execute_export(cmd_arr);
	// else if (ft_strncmp(cmd_arr[0], "unset", 6))
	// 	execute_unset(cmd_arr);
	// else if (ft_strncmp(cmd_arr[0], "env", 4))
	// 	execute_env();
	// else if (ft_strncmp(cmd_arr[0], "exit", 5))
	// 	execute_exit(cmd_arr);
}

/* As a child process checks access & executes command
	It calls accessor object.
	*/
int	fork_process(t_data *data, t_exec_data *exec_data, char **cmd_arr,
					char **paths)
{
	int			pid;
	t_exec_cmd	execute;
	int			status;

	pid = fork();
	if (pid == 0)
	{
		dup_pipe(exec_data);
		check_or_execute_builin(data, cmd_arr);
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
