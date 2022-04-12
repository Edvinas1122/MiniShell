/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:43:53 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/12 10:16:53 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"

typedef struct s_data	t_data;

int	parser(t_data *data, char **line);
/* Parser's calls */
int	env_resolver(t_data *data, char **input);
int	lexer(char *line, t_list **clean_input);
int	split_into_commands(t_data *data, t_list *clean_input);

#endif
