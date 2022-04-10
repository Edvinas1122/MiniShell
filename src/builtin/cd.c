/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:57:38 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/08 10:09:27 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	cd_to_home(t_data *data)
{
	char	*home_dir;

	home_dir = get_env_value(*data->envp_data.envp_cp, "HOME");
	if (home_dir[0] == '\0')
	{
		write(1, "HOME is not set\n", 16);
		free(home_dir);
	}
	if (change_dir(data, home_dir))
		perror("error\n");
	free(home_dir);
}

static void	cd_to_relative(t_data *data, char **argv)
{
	char	*cwd;
	char	*tmp;
	char	*relative;
	(void)data;

	cwd = get_cwd();
	tmp = ft_strjoin(cwd, "/");
	relative = ft_strjoin(tmp, argv[1]);
	change_dir(data, relative);
	free(tmp);
	free(cwd);
}

static void	print_cwd(void)
{
	char	*cwd;

	cwd = get_cwd();
	ft_putstr_fd(cwd, 1);
	write(1, "\n", 1);
	free(cwd);
}

/* The CD builtin */
/* Does not implament symlinks */
int	execute_cd(t_data *data, char **argv)
{
	if (argv[1] == NULL)
		cd_to_home(data);
	else if (argv[1][0] == '/')
		change_dir(data, argv[1]);
	else
		cd_to_relative(data, argv);
	print_cwd();
	return (EXIT_SUCCESS);
}
