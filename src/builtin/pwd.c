/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:56:38 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/11 23:27:32 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	execute_pwd(t_data *data, char **argv)
{
	if (argv[1])
	{
		ft_putendl_fd("pwd: too many arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_putendl_fd(&data->envp_data.pwd[4], STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
