/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:42:37 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/07 19:06:15 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libs/libft/libft.h"
# include "constructor/constructor.h"
# include "parser/parser.h"
# include "executor/executor.h"
# include "utils/utils.h"
# include "builtin/builtin.h"

/* Command data */
typedef struct s_command
{
	t_list	**commands;
	char	**paths;
	int		input_fd;
	int		output_fd;
}			t_command;

/* Environment data */
typedef struct s_envp_data
{
	t_list	**envp_cp;
	t_list	**envp_empty;
	t_list	*pwd_list;
	char	*pwd;
	char	*old_pwd;
	char	*pwd_slink;
	int		exit_status;
}				t_envp_data;

/* Main data struct */
typedef struct s_data
{
	t_envp_data	envp_data;
	t_command	command;
}				t_data;

#endif
