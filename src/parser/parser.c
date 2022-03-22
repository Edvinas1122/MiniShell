/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:43:37 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/22 19:40:49 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser(t_data *data, char *line)
{
	char	**line_split;

	while (*line && *line == ' ')
		line++;
	while (*line)
	{
		if (*line == '>' || *line == '<')
			parse_redir(data, &line);
		else if (*line == '"' || *line == '\'')
			parse_quote(data, &line);
		else if (!ft_ismetachar(*line) && !ft_isspace(*line))
			parse_command(data, &line);
		else
			line++;
	}
}
