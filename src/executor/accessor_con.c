/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessor_con.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:28:35 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/05 18:24:12 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/* Appends command to env PATHS and checks if paths are valid */
static char	*path_string_command(char **paths, char *cmd)
{
	char	*path;
	char	*tmp;
	int		check;
	int		i;

	check = -1;
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		check = access(path, X_OK);
		if (check == 0)
			break ;
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
	if (ft_strchr(cmd_arr[0], '/'))
		cmd.path_cmd = ft_strdup(cmd_arr[0]);
	else
		cmd.path_cmd = path_string_command(paths, cmd_arr[0]);
	return (cmd);
}
