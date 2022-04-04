/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:06:36 by emomkus           #+#    #+#             */
/*   Updated: 2022/02/20 23:26:45 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipes.h"

static void	execute_command(t_command *command, char **envp)
{
	execve(command->directory, command->args, envp);
}

static void	redirect_input(t_fd_object *fd, t_command *command, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd->in_file, STDIN_FILENO);
		dup2(fd->pipe1[1], STDOUT_FILENO);
		execute_command(command, envp);
	}
	waitpid(pid, NULL, 0);
	close(fd->pipe1[1]);
	close(fd->in_file);
}

static void	redirect_output(t_fd_object *fd, t_command *command, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd->pipe1[0], STDIN_FILENO);
		dup2(fd->out_file, STDOUT_FILENO);
		execute_command(command, envp);
	}
	waitpid(pid, NULL, 0);
	close(fd->pipe1[0]);
	close(fd->out_file);
}

static void	pipe_forking(t_fd_object *fd, t_command *command, char **envp, int i)
{
	int	pid;

	pid = fork();
	if (!(i % 2))
		pipe(fd->pipe1);
	else
		pipe(fd->pipe2);
	if (pid == 0)
	{
		if (!(i % 2))
		{
			dup2(fd->pipe1[0], STDIN_FILENO);
			dup2(fd->pipe2[1], STDOUT_FILENO);
		}
		else
		{
			dup2(fd->pipe2[0], STDIN_FILENO);
			dup2(fd->pipe1[1], STDOUT_FILENO);
		}
		execute_command(command, envp);
	}
	waitpid(pid, NULL, 0);
	if (!(i % 2))
	{
		close(fd->pipe1[0]);
		close(fd->pipe2[1]);
	}
	else
	{
		close(fd->pipe2[0]);
		close(fd->pipe1[1]);
	}
}

static void	output_to_terminal(t_fd_object *fd, t_command *command, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd->pipe1[0], STDIN_FILENO);
		execute_command(command, envp);
	}
	waitpid(pid, NULL, 0);
	close(fd->pipe1[0]);
}

void	fork_process(t_full_command obj_str, char **envp)
{
	int	i;

	i = 0;
	pipe(obj_str.fd.pipe1);
	if (obj_str.info.input)
	{
		redirect_input(&(obj_str.fd), obj_str.commands[i], envp);
		i++;
	}
	while (*(obj_str.info.num_of_commands)-- != 1)
	{
		pipe_forking(&(obj_str.fd), obj_str.commands[i], envp, i);
		i++;
	}
	if (obj_str.info.output)
		redirect_output(&(obj_str.fd), obj_str.commands[i], envp);
	else
		output_to_terminal(&(obj_str.fd), obj_str.commands[i], envp);
}
