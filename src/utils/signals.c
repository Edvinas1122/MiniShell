/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 04:32:08 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/12 18:48:42 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// SIGINT handler for parent processs
static void	sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_redisplay();
	}
}

// Register SIGINT handler and ignore SIGQUIT for parent process
void	handle_parent_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

// SIGINT and SIGQUIT handler for child process
static void	child_signal_handler(int signal)
{
	if (signal == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
	else if (signal == SIGINT)
		ft_putchar_fd('\n', STDERR_FILENO);
}

// Register SIGINT and SIGQUIT handler for child process
void	handle_child_signals(void)
{
	signal(SIGINT, child_signal_handler);
	signal(SIGQUIT, child_signal_handler);
}
