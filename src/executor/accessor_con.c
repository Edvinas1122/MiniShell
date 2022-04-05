/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessor_con.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:28:35 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/05 15:50:40 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"


/* Appends command to env PATHS and checks if paths are valid */
static char	*path_string_command(char **paths, char *cmd)
{
	char	*path;
	int		check;
	int		i;

	check = -1;
	i = 0;
	while (paths[i])
	{
		// join /
		path = ft_strjoin(paths[i], cmd);
		check = access(path, X_OK);
		if (check == 0)
			break;
		free(path);
		i++;
	}
	if (check == 0)
		return (path);
	else
		return (NULL);
}

/* Returns struct of final executor data, checks for command path with access
	*/
t_exec_cmd	accessor_con(char **cmd_arr, char **paths)
{
	t_exec_cmd	cmd;

	cmd.cmd_arr = cmd_arr;
	cmd.path_cmd = path_string_command(paths, cmd_arr[0]);
	return (cmd);
}
