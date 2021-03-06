/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:21:43 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/08 10:45:36 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Parser cleaner, if clean all then clean commands as well
static int	free_parser(t_data *data, t_list **clean_input, char **line,
	int clean_all)
{
	if (*line)
		free(*line);
	ft_lstclear(clean_input, free);
	if (clean_all)
	{
		ft_lstclear(data->command.commands, (void (*)(void *))free_array);
		free_array(data->command.paths);
		data->command.paths = NULL;
	}
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

// Get path in 2d char array from envp
// Return NULL if empty
static char	**get_paths_array(t_list *envp)
{
	char	*path;
	char	**paths;

	path = get_env_value(envp, "PATH");
	if (!path)
		return (NULL);
	else if (!ft_strlen(path))
	{
		free(path);
		return (NULL);
	}
	paths = ft_split(path, ':');
	free(path);
	return (paths);
}

// Parse the line and return set of commands for executor
// Return 0 if error otherwise 1
int	parser(t_data *data, char **line)
{
	char	*tmp;
	t_list	*clean_input;

	clean_input = NULL;
	data->command.paths = get_paths_array(*data->envp_data.envp_cp);
	data->command.input_fd = STDIN_FILENO;
	data->command.output_fd = STDOUT_FILENO;
	tmp = ft_strtrim(*line, " \v\t\f\r\n");
	free(*line);
	*line = tmp;
	if (!*line || !env_resolver(data, line))
		return (parser_error(data, &clean_input, line, NULL));
	if (!lexer(*line, &clean_input))
		return (parser_error(data, &clean_input, line, NULL));
	if (!split_into_commands(data, clean_input))
		return (free_parser(data, &clean_input, line, 1));
	free_parser(data, &clean_input, line, 0);
	return (1);
}
