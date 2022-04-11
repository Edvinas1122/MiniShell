/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print_alone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:00:45 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/11 23:27:19 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	**dup_env(t_envp_data envp_data)
{
	char	**env;
	t_list	*list;
	int		i;

	env = ft_calloc(ft_lstsize(*envp_data.envp_cp) + \
		ft_lstsize(*envp_data.envp_empty) + 1, sizeof(char *));
	i = 0;
	list = *envp_data.envp_cp;
	while (list)
	{
		env[i] = list->content;
		list = list->next;
		i++;
	}
	list = *envp_data.envp_empty;
	while (list)
	{
		env[i] = list->content;
		list = list->next;
		i++;
	}
	return (env);
}

static void	sort_env(char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[i + 1])
	{
		if (ft_strncmp(env[i], env[i + 1], ft_strlen(env[i])) > 0)
		{
			tmp = env[i + 1];
			env[i + 1] = env[i];
			env[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

static void	print_env(char **env)
{
	int	i;

	while (*env)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		i = 0;
		while ((*env)[i])
		{
			if ((*env)[i] == '\\' || (*env)[i] == '$'
				|| (*env)[i] == '"')
				ft_putchar_fd('\\', STDOUT_FILENO);
			ft_putchar_fd((*env)[i], STDOUT_FILENO);
			if ((*env)[i] == '=')
				ft_putchar_fd('"', STDOUT_FILENO);
			i++;
		}
		if (ft_strchr(*env, '='))
			ft_putchar_fd('"', STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		env++;
	}
}

int	export_print_alone(t_envp_data envp_data)
{
	char	**env;

	env = dup_env(envp_data);
	sort_env(env);
	print_env(env);
	free(env);
	return (EXIT_SUCCESS);
}
