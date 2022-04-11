/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:57:38 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/11 21:04:33 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	cd_to_home(t_data *data)
{
	char	*home_dir;

	home_dir = get_env_value(*data->envp_data.envp_cp, "HOME");
	if (home_dir[0] == '\0')
	{
		write(2, "HOME is not set\n", 16);
		free(home_dir);
		return (EXIT_FAILURE);
	}
	change_dir(data, home_dir);
	free(home_dir);
	return (EXIT_SUCCESS);
}

// static void	cd_to_relative(t_data *data, char **argv)
// {
// 	char	*cwd;
// 	char	*tmp;
// 	char	*relative;
// 	(void)data;

// 	cwd = get_cwd();
// 	tmp = ft_strjoin(cwd, "/");
// 	relative = ft_strjoin(tmp, argv[1]);
// 	change_dir(data, relative);
// 	free(tmp);
// 	free(cwd);
// }

// static void	print_cwd(void)
// {
// 	char	*cwd;

// 	cwd = get_cwd();
// 	ft_putstr_fd(cwd, 1);
// 	write(1, "\n", 1);
// 	free(cwd);
// }

/* The CD builtin */
/* Does not implament symlinks */
int	execute_cd(t_data *data, char **argv)
{
	if (argv[1] == NULL)
		return (cd_to_home(data));
	else
		return (change_dir(data, argv[1]));
	// print_cwd();
	return (EXIT_SUCCESS);
}
