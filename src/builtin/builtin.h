/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:20:17 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/09 18:01:38 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"

int		execute_echo(t_data *data, char **argv);
int		execute_unset(t_data *data, char **argv);
int		execute_env(t_data *data, char **argv);
int		execute_exit(t_data *data, char **argv);
int		execute_export(t_data *data, char **argv);

#endif
