/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:20:17 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/07 17:25:42 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"

int	execute_echo(t_data *data, char **argv);
int	execute_unset(t_data *data, char **argv);
int	execute_cd(t_data *data, char **argv);

#endif
