/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:20:17 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/10 21:04:45 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"

int		execute_echo(t_data *data, char **argv);
int		execute_unset(t_data *data, char **argv);
int		execute_env(t_data *data, char **argv);
int		execute_exit(t_data *data, char **argv);

#endif
