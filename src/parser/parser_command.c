/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:39:55 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/22 19:52:49 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**get_command(char **line)
{
	char	**command;
	int		command_len;

	command_len = get_command_len(*line);
	command = ft_calloc(command_len, sizeof(char *));
	*command = ft_substr(*line, 0, ft_strchr(*line, ))
}

void	parse_command(t_data *data, char **line)
{
	ft_lstadd_back(data->command.commands, ft_lstnew(get_command(line)));
}
