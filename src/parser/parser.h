/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:43:53 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/04 00:33:58 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"

typedef struct s_data	t_data;

int		env_resolver(t_data *data, char **input);
int		lexer(t_data *data, char *line);
int		parser(t_data *data, char **line);
int		split_into_commands(t_data *data, t_list *clean_input);

#endif
