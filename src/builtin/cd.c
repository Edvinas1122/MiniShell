/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:57:38 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/12 21:04:10 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	update_envp(t_envp_data envp_data)
{
	char	*old_pwd;

	if (find_list(*envp_data.envp_cp, "PWD=", 0))
	{
		free(envp_data.pwd_list->content);
		envp_data.pwd_list->content = NULL;
		envp_data.pwd_list->content = ft_strjoin("PWD=", envp_data.pwd);
	}
	old_pwd = ft_strjoin("OLDPWD=", envp_data.old_pwd);
	if (find_list(*envp_data.envp_cp, "OLDPWD=", 0))
	{
		free(envp_data.old_pwd_list->content);
		envp_data.old_pwd_list->content = old_pwd;
	}
	else if (find_list(*envp_data.envp_empty, "OLDPWD", 1))
	{
		find_delete_list(envp_data.envp_empty, "OLDPWD", free);
		ft_lstadd_back(envp_data.envp_cp, ft_lstnew(old_pwd));
		envp_data.old_pwd_list = find_list(*envp_data.envp_cp, "OLDPWD=", 0);
	}
}

static int	change_dir(t_data *data, char *dir)
{
	char	*tmp;

	if (chdir(dir) < 0)
	{
		perror(dir);
		return (EXIT_FAILURE);
	}
	tmp = get_cwd();
	if (data->envp_data.old_pwd)
		free(data->envp_data.old_pwd);
	data->envp_data.old_pwd = data->envp_data.pwd;
	data->envp_data.pwd = tmp;
	update_envp(data->envp_data);
	return (EXIT_SUCCESS);
}

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
