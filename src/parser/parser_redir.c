/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:46:36 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/22 19:35:13 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	get_output_fd(char **line)
{

}

void	parser_redir(t_data *data, char **line)
{
	data->command.output_fd = STDOUT_FILENO;
	data->command.input_fd = STDIN_FILENO;
	if (**line == '>' && *(*line + 1))
	{
		*line++;
		data->command.output_fd = get_output_fd(line);
	}
	else if (**line == '<' && *(*line + 1))
	{
		*line++;
		if (**line == '<')
			data->command.input_fd = get_heredoc_fd(line);
		else
			data->command.input_fd = get_input_fd(line);
	}
}
