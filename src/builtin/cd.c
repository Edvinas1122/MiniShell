/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:57:38 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/12 00:20:12 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	cd_to_home(t_data *data)
{
	char	*home_dir;

	home_dir = get_env_value(*data->envp_data.envp_cp, "HOME");
	if (home_dir[0] == '\0')
	{
		ft_putendl_fd("cd: HOME not set\n", STDERR_FILENO);
		free(home_dir);
		return (EXIT_FAILURE);
	}
	change_dir(data, home_dir);
	free(home_dir);
	return (EXIT_SUCCESS);
}

/* The CD builtin */
/* Does not implament symlinks */
int	execute_cd(t_data *data, char **argv)
{
	if (argv[1] == NULL)
		return (cd_to_home(data));
	else
		return (change_dir(data, argv[1]));
	return (EXIT_SUCCESS);
}
