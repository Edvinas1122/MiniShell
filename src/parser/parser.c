/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:21:43 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/04 00:34:03 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Parser cleaner, if clean all then clean commands as well
// TODO: revise command cleaner
static int	free_parser(t_data *data, t_list **clean_input, char **line,
	int clean_all)
{
	if (*line)
		free(*line);
	ft_lstclear(clean_input, free);
	if (clean_all)
		ft_lstclear(data->command.commands, free);
	return (0);
}

// Error handler
static int	parser_error(t_data *data, t_list **clean_input, char **line,
	char *err)
{
	free_parser(data, clean_input, line, 1);
	if (err)
		ft_putendl_fd(err, 2);
	else
		perror(err);
	return (0);
}

// Parse the line and return set of commands for executor
// Return 0 if error otherwise 1
int	parser(t_data *data, char **line)
{
	char	*tmp;

	data->clean_input = NULL;
	data->command.commands = ft_calloc(1, sizeof(t_list *));
	data->command.input_fd = STDIN_FILENO;
	data->command.output_fd = STDOUT_FILENO;
	tmp = ft_strtrim(*line, " \v\t\f\r\n");
	free(*line);
	*line = tmp;
	if (!*line || !data->command.commands || !env_resolver(data, line))
		return (parser_error(data, &data->clean_input, line, NULL));
	if (!lexer(data, *line))
		return (parser_error(data, &data->clean_input, line, NULL));
	if (!split_into_commands(data, data->clean_input))
		return (free_parser(data, &data->clean_input, line, 1));
	free_parser(data, &data->clean_input, line, 0);
	return (1);
}
