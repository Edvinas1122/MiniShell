/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:10:46 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/08 19:24:17 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	unset_env(t_list *envp, char *env)
{
	t_list	*tmp;

	while (envp)
	{
		if (envp->next && !ft_strncmp(envp->next->content,
				env, ft_strlen(env)))
		{
			tmp = envp->next->next;
			ft_lstdelone(envp->next, free);
			envp->next = tmp;
			break ;
		}
		envp = envp->next;
	}
}

int	execute_unset(t_data *data, char **argv)
{
	char	*to_find;
	int		exit_status;

	exit_status = EXIT_SUCCESS;
	while (*++argv)
	{
		if (!is_valid_env(*argv))
		{
			exit_status = EXIT_FAILURE;
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(*argv, 2);
			ft_putendl_fd("': not a valid identifier", 2);
			continue ;
		}
		to_find = ft_strjoin(*argv, "=");
		if (!to_find)
			return (EXIT_FAILURE);
		unset_env(*data->envp_data.envp_cp, to_find);
		free(to_find);
	}
	return (exit_status);
}
