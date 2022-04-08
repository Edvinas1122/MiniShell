/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:23:04 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/08 20:25:05 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// Check if it's a "-n" flag with any amount of n
static int	is_nl_flag(char *str)
{
	if (!str && *str != '-')
		return (0);
	str++;
	while (*str && *str != 'n')
	{
		if (*str != 'n')
			return (0);
		str++;
	}
	return (1);
}

int	execute_echo(t_data *data, char **argv)
{
	int	nl;
	int	printed;

	(void)data;
	argv++;
	printed = 0;
	nl = 1;
	while (*argv)
	{
		if (!printed && is_nl_flag(*argv))
			nl = 0;
		else
		{
			if (printed)
				ft_putchar_fd(' ', STDOUT_FILENO);
			ft_putstr_fd(*argv, STDOUT_FILENO);
			printed = 1;
		}
		argv++;
	}
	if (nl)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
