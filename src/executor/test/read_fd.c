/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:38:11 by emomkus           #+#    #+#             */
/*   Updated: 2022/03/22 16:20:34 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipes.h"

static int	array_len(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

#ifndef OS

static char	**append_slash(char	**input_array)
{
	char	**array;
	int		i;

	i = 0;
	array = malloc((sizeof(char *) * array_len(input_array)) + 1);
	while (input_array[i])
		array[i] = ft_strjoin_free(input_array[i], "/");
	
	return (array);
}

#else

static char	**append_slash(char	**input_array)
{
	return (input_array);
}

#endif

static int	find_index_of_path_var(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (i);
}

static char	**enviroment_paths_arr(char **envp)
{
	int		i;
	char	*path_str;
	char	**array_of_paths;
	char	**array_of_paths_final;

	i = find_index_of_path_var(envp);
	path_str = ft_strtrim(envp[i], "PATH=");
	array_of_paths = ft_split(path_str, ':');
	array_of_paths_final = append_slash(array_of_paths);
	// free(path_str);
	ft_putstr_fd(array_of_paths_final[0], 1);
	ft_putchar_fd('\n', 1);
	// "/usr/bin/"
	// "/asda/asd/"
	return (array_of_paths_final);
}

int	main(int argc, char **argv, char **envp)
{
	t_full_command	obj;
	int				*numbr_of_commands;

	enviroment_paths_arr(envp);
	numbr_of_commands = malloc(sizeof(int));
	*numbr_of_commands = 1;
	obj.info.num_of_commands = numbr_of_commands;
	obj.commands = input_parce(argc, argv, envp);
	obj.fd.in_file = open("text.txt", O_RDONLY);
	obj.info.input = 1;
	// obj.fd.out_file = open("out.txt", O_WRONLY | O_TRUNC | O_CREAT);
	// obj.info.output = 1;
	fork_process(obj, envp);
	// pipe(fd.pipe);
	// /*FORK PROCESS*/
	// fork_process(&fd, commands[0], envp);
	// /*FORK PROCESS 2*/
	// fork_process2(&fd, commands[1], envp);
	return(0);
}
