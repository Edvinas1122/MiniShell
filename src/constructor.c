/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:51:44 by emomkus           #+#    #+#             */
/*   Updated: 2022/03/22 15:39:38 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* retunrs copy of environment */
static t_list	**enviroment_list_con(char **envp)
{
	t_list	**envp_cp;
	char	*env_vars_tmp;
	int		i;

	i = 0;
	envp_cp = malloc(sizeof(t_list *));
	while (envp[i])
	{
		env_vars_tmp = ft_strdup(envp[i]);
		ft_lstadd_back(envp_cp, ft_lstnew(env_vars_tmp));
		i++;
	}
	return (envp_cp);
}

// Utils
t_list	*get_str_list(t_list **envp_cp, char *to_find)
{
	t_list	*pwd_list;

	pwd_list = *envp_cp;
	while (pwd_list)
	{
		if (!ft_strncmp((char *)pwd_list->content, to_find, ft_strlen(to_find)))
			break ;
		pwd_list = pwd_list->next;
	}
	return (pwd_list);
}

/* initialises "enviromental" data */
static t_envp_data	environment_con(char **envp)
{
	t_envp_data	envp_data;

	envp_data.envp_cp = enviroment_list_con(envp);
	envp_data.pwd_list = get_str_list(envp_data.envp_cp, "PWD=");
	return (envp_data);
}

/* initialises all data */
t_data	*constructor(char **envp)
{
	t_data *data;

	data = malloc(sizeof(data));
	data->envp_data = environment_con(envp);
	return (data);
}