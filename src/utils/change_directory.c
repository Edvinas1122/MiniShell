/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:48:15 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/12 19:02:42 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

int	change_dir(t_data *data, char *dir)
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
