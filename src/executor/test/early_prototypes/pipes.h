/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:47:17 by emomkus           #+#    #+#             */
/*   Updated: 2022/03/22 16:14:54 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_H
# define PIPES_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libs/libft/libft.h"

/* Executor runtime data */
typedef struct	s_executor
{
	int		pipe1[2];
	int		pipe2[2];
}				t_executor;

typedef struct s_fd_object
{
	int	in_file;
	int	out_file;
	int	pipe1[2];
	int	pipe2[2];
}	t_fd_object;

typedef struct s_command
{
	char	**args;
	char	*directory;
}	t_command;

typedef struct s_info_str
{
	int			*num_of_commands;
	char		input;
	char		input_del;
	char		output;
	char		output_append;
}	t_info_str;


typedef struct s_full_command
{
	t_command	**commands;
	t_fd_object	fd;
	t_info_str	info;		
}	t_full_command;


t_command	**input_parce(int argc, char **argv, char **envp);
int 		printfd(int	fd);
void		fork_process(t_full_command obj_str, char **envp);

#endif