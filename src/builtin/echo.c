/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:23:04 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/05 21:29:14 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	execute_echo(char **argv)
{
	int	i;
	int	nl;

	nl = 1;
	i = 1;
	if (argv[i] && !ft_strncmp(argv[i], "-n", 3))
	{
		i++;
		nl = 0;
	}
	while (argv[i])
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		i++;
	}
	if (nl)
		ft_putchar_fd('\n', STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
