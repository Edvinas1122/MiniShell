/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:42:37 by emomkus           #+#    #+#             */
/*   Updated: 2022/03/22 18:45:32 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libs/libft/libft.h"
# include "utils.h"
//# include "executor/executor.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>

/* Command data */
typedef struct s_command
{
	t_list	**commands;
	char	**paths;
	int		input_fd;
	int		output_fd;
}			t_command;

/* Eviromental data */
typedef struct s_envp_data
{
	t_list	**envp_cp;
	t_list	*pwd_list;
}				t_envp_data;

/* Main data struct */
typedef struct s_data
{
	t_envp_data	envp_data;
	t_command	command;
}				t_data;

t_data	*constructor(char **envp);

#endif
