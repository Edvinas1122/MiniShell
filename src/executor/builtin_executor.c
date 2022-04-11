/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_executor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:53:37 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/11 18:50:30 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

// Check if it is a built in function
// Return pointer to built in function otherwise NULL
static void	*get_builtin_function(char *command)
{
	if (!ft_strncmp(command, "echo", 5))
		return (&execute_echo);
	else if (!ft_strncmp(command, "cd", 3))
		return (&execute_cd);
	// else if (!ft_strncmp(command, "pwd", 4))
	// 	return (&execute_pwd);
	else if (!ft_strncmp(command, "export", 7))
		return (&execute_export);
	else if (!ft_strncmp(command, "unset", 6))
		return (&execute_unset);
	else if (!ft_strncmp(command, "env", 4))
		return (&execute_env);
	else if (!ft_strncmp(command, "exit", 5))
		return (&execute_exit);
	return (NULL);
}

// Dup2 pipe fd to std fd if itsn't std fd and dup std fd to save it
static void	dup_pipe(t_exec_data *exec_data, int *original_input,
	int *original_output)
{
	if (exec_data->pipe_shift == 0)
	{
		if (exec_data->pipe1[0] != STDIN_FILENO)
			*original_input = dup(STDIN_FILENO);
		dup2_and_close(exec_data->pipe1[0], STDIN_FILENO);
		if (exec_data->pipe2[1] != STDOUT_FILENO)
			*original_output = dup(STDOUT_FILENO);
		dup2_and_close(exec_data->pipe2[1], STDOUT_FILENO);
	}
	else
	{
		if (exec_data->pipe2[0] != STDIN_FILENO)
			*original_input = dup(STDIN_FILENO);
		dup2_and_close(exec_data->pipe2[0], STDIN_FILENO);
		if (exec_data->pipe1[1] != STDOUT_FILENO)
			*original_output = dup(STDOUT_FILENO);
		dup2_and_close(exec_data->pipe1[1], STDOUT_FILENO);
	}
}

int	check_or_execute_builtin(t_data *data, t_exec_data *exec_data,
	char **cmd_arr)
{
	int	(*builtin)(t_data *, char **);
	int	original_input;
	int	original_output;

	builtin = get_builtin_function(cmd_arr[0]);
	if (!builtin)
		return (0);
	original_input = -1;
	original_output = -1;
	dup_pipe(exec_data, &original_input, &original_output);
	data->envp_data.exit_status = builtin(data, cmd_arr);
	if (original_input > -1)
		dup2_and_close(original_input, STDIN_FILENO);
	if (original_output > 1)
		dup2_and_close(original_output, STDOUT_FILENO);
	return (1);
}
