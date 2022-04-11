/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:56:38 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/11 21:44:28 by emomkus          ###   ########.fr       */
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