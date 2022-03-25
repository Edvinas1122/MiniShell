/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:51:44 by emomkus           #+#    #+#             */
/*   Updated: 2022/03/28 18:20:40 by cthien-h         ###   ########.fr       */
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

/* initialises "enviromental" data */
static t_envp_data	environment_con(char **envp)
{
	t_envp_data	envp_data;

	envp_data.envp_cp = enviroment_list_con(envp);
	envp_data.pwd_list = get_str_list(*envp_data.envp_cp, "PWD=");
	return (envp_data);
}

/* initialises all data */
t_data	*constructor(char **envp)
{
	t_data	*data;

	data = malloc(sizeof(data));
	data->envp_data = environment_con(envp);
	return (data);
}
