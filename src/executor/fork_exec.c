/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:58:57 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/04 19:15:50 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"


/*execute execve()*/
static void	execute_command(t_exec_cmd exe, char **envp)
{
	execve(exe.path_cmd, exe.cmd_arr, envp);
}

/* Dubs pipe FD, file FD, FD regarding "rotary motion" */
static void	dub_pipe(t_exec_data *exec_data)
{
	if (exec_data->pipe_shift == 0)
	{
		dup2(fd->pipe1[0], STDIN_FILENO);
		dup2(fd->pipe2[1], STDOUT_FILENO);
	}
	else
	{
		dup2(fd->pipe2[0], STDIN_FILENO);
		dup2(fd->pipe1[1], STDOUT_FILENO);
	}
}

/* Closes regarding "rotary motion" */
static void close_pipe(t_exec_data *exec_data)
{
	if (exec_data->pipe_shift == 0)
	{
		close(fd->pipe1[0]);
		if (fd->pipe2[1] != 1)
			close(fd->pipe2[1]);
	}
	else
	{
		if (fd->pipe2[0] != 0)
			close(fd->pipe2[0]);
		if (fd->pipe1[1] != 1)
			close(fd->pipe1[1]);
	}
}


/* checks for builtins and executes them if finds
	no invalid argument check */
// static void	check_or_execute_builin(char *cmd_arr)
// {
// 	if (ft_strncmp(cmd_arr[0], "echo", 5))
// 		execute_echo(cmd_arr);
// 	else if (ft_strncmp(cmd_arr[0], "cd", 3))
// 		execute_cd(cmd_arr);
// 	else if (ft_strncmp(cmd_arr[0], "pwd", 4))
// 		execute_pwd(cmd_arr);
// 	else if (ft_strncmp(cmd_arr[0], "export", 7))
// 		execute_export(cmd_arr);
// 	else if (ft_strncmp(cmd_arr[0], "unset", 6))
// 		execute_unset(cmd_arr);
// 	else if (ft_strncmp(cmd_arr[0], "env", 4))
// 		execute_env();
// 	else if (ft_strncmp(cmd_arr[0], "exit", 5))
// 		execute_exit(cmd_arr);
// }

/* As a child process checks access & executes command 
	It calls accessor object.
	*/
void	fork_process(t_exec_data *exec_data, void **cmd_arr, char **paths)
{
	int			pid;
	t_exec_cmd	execute;

	pid = fork();
	if (pid == 0)
	{
		dup_pipe(exec_data);
		//check_or_execute_builin(cmd_arr);
		execute = accessor_con(cmd_arr, paths);
		execute_command(execute, NULL);
	}
	waitpid(pid, NULL, 0);
	close_pipe(exec_data);
}
