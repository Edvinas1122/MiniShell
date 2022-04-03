/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:55:08 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/03 17:28:24 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTRUCTOR_H
# define CONSTRUCTOR_H

# include "../minishell.h"

typedef struct s_data	t_data;

t_data	*constructor(char **envp);
void	deconstructor(t_data *data);

#endif
