/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:10:46 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/09 18:43:10 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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
			ft_putstr_fd("unset: `", STDERR_FILENO);
			ft_putstr_fd(*argv, STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			continue ;
		}
		to_find = ft_strjoin(*argv, "=");
		if (!to_find)
			return (EXIT_FAILURE);
		find_delete_list(data->envp_data.envp_empty, *argv, free);
		find_delete_list(data->envp_data.envp_cp, to_find, free);
		free(to_find);
	}
	return (exit_status);
}
