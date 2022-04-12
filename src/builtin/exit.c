/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:07:59 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/12 20:52:58 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	exit_with_arg(char *arg)
{
	int	status;

	if (ft_isnbr(arg) && ft_strlen(arg) < 19)
	{
		ft_putendl_fd("exit", 2);
		status = ft_atoll(arg);
		free(arg);
		exit(status % 256);
	}
	else
	{
		ft_putstr_fd("exit\nexit: ", 2);
		ft_putstr_fd(arg, 2);
		free(arg);
		ft_putendl_fd(": numeric argument required", 2);
		exit(255);
	}
}

int	execute_exit(t_data *data, char **argv)
{
	char	*str;
	int		status;

	if (argv[1] && ft_isnbr(argv[1]) && argv[2])
	{
		ft_putendl_fd("exit\nexit: too many arguments", 2);
		return (EXIT_FAILURE);
	}
	str = ft_strdup(argv[1]);
	status = data->envp_data.exit_status;
	ft_lstclear(data->command.commands, (void (*)(void *))free_array);
	free_array(data->command.paths);
	deconstructor(data);
	if (str)
		exit_with_arg(str);
	free(str);
	exit(status);
}
