/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:05:24 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/09 19:09:02 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	error(char *env_name)
{
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(env_name, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
	free(env_name);
	return (0);
}

static int	set_empty_env(t_envp_data envp_data, char *env_name)
{
	t_list	*list;
	char	*tmp;

	if (!is_valid_env(env_name))
		return (error(env_name));
	list = find_list(*envp_data.envp_empty, env_name, 1);
	if (list)
		return (1);
	tmp = ft_strjoin(env_name, "=");
	if (!tmp)
		return (0);
	list = find_list(*envp_data.envp_cp, tmp, 0);
	free(tmp);
	if (list)
		return (1);
	ft_lstadd_back(envp_data.envp_empty, ft_lstnew(ft_strdup(env_name)));
	free(env_name);
	return (1);
}

static int	set_env(t_envp_data envp_data, char *env)
{
	char	*env_name;
	char	*tmp;
	t_list	*env_list;

	env_name = ft_substr(env, 0, ft_strchr(env, '=') - env);
	if (!env_name)
		return (0);
	if (!is_valid_env(env_name))
		return (error(env_name));
	find_delete_list(envp_data.envp_empty, env_name, free);
	tmp = ft_strjoin(env_name, "=");
	free(env_name);
	if (!tmp)
		return (0);
	env_list = find_list(*envp_data.envp_cp, tmp, 0);
	if (env_list)
	{
		free(env_list->content);
		env_list->content = ft_strdup(env);
	}
	else
		ft_lstadd_back(envp_data.envp_cp, ft_lstnew(ft_strdup(env)));
	free(tmp);
	return (1);
}

static int	print_env(t_envp_data envp_data)
{
	t_list	*list;

	list = *envp_data.envp_cp;
	while (list)
	{
		ft_putendl_fd(list->content, STDOUT_FILENO);
		list = list->next;
	}
	list = *envp_data.envp_empty;
	while (list)
	{
		ft_putendl_fd(list->content, STDOUT_FILENO);
		list = list->next;
	}
	return (EXIT_SUCCESS);
}

int	execute_export(t_data *data, char **argv)
{
	int	status;

	status = EXIT_SUCCESS;
	if (!argv[1])
		return (print_env(data->envp_data));
	else
	{
		argv++;
		while (*argv)
		{
			if ((ft_strchr(*argv, '=')
					&& !set_env(data->envp_data, *argv))
				|| (!ft_strchr(*argv, '=')
					&& !set_empty_env(data->envp_data, ft_strdup(*argv))))
				status = EXIT_FAILURE;
			argv++;
		}
	}
	return (status);
}
