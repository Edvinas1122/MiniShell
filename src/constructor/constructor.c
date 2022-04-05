/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:51:44 by emomkus           #+#    #+#             */
<<<<<<< HEAD:src/constructor.c
/*   Updated: 2022/04/04 19:21:01 by emomkus          ###   ########.fr       */
=======
/*   Updated: 2022/04/04 20:43:19 by cthien-h         ###   ########.fr       */
>>>>>>> origin/cthien-h:src/constructor/constructor.c
/*                                                                            */
/* ************************************************************************** */

#include "constructor.h"

/* retunrs copy of environment */
static t_list	**enviroment_list_con(char **envp)
{
	t_list	**envp_cp;
	char	*env_vars_tmp;
	int		i;

	envp_cp = ft_calloc(1, sizeof(t_list *));
	*envp_cp = NULL;
	i = 0;
	while (envp[i])
	{
		env_vars_tmp = ft_strdup(envp[i]);
		ft_lstadd_back(envp_cp, ft_lstnew(env_vars_tmp));
		i++;
	}
	return (envp_cp);
}

/* initialises "enviromental" data */
static t_envp_data	initialise_envp(char **envp)
{
	t_envp_data	envp_data;

	envp_data.envp_cp = enviroment_list_con(envp);
	envp_data.pwd_list = find_list(*envp_data.envp_cp, "PWD");
	return (envp_data);
}

/* initialises all data */
// TODO: Handle empty envp or commands
t_data	*constructor(char **envp)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	data->envp_data = initialise_envp(envp);
	data->command.commands = ft_calloc(1, sizeof(t_list *));
	return (data);
}
