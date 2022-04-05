/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_splitter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:15:16 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/05 18:21:05 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Error handler
static int	error(char *err, char **command)
{
	free_array(command);
	if (err)
		ft_putendl_fd(err, 2);
	else
		perror(err);
	return (0);
}

// Open heredoc pipe and write the heredoc string to it
// TODO: revise error case
static int	get_heredoc(char *stop_str)
{
	int		heredoc_pipe[2];
	char	*line;

	pipe(heredoc_pipe);
	while (42)
	{
		line = readline("> ");
		if (!line || !ft_strncmp(line, stop_str, ft_strlen(stop_str) + 1))
			break ;
		write(heredoc_pipe[1], line, ft_strlen(line));
		write(heredoc_pipe[1], "\n", 1);
	}
	close(heredoc_pipe[1]);
	return (heredoc_pipe[0]);
}

// Get input/ouput fd
// Return 0 if error otherwise 1
// TODO: discuss how to handle << heredoc
static int	get_inout_fd(t_data *data, t_list **list, char **command)
{
	char	*filename;

	if (!(*list)->next)
		return (error("syntax error near unexpected token `newline'",
				command));
	filename = (*list)->next->content;
	if (!ft_strncmp((*list)->content, ">>", 3))
		data->command.output_fd = open(filename,
				O_RDWR | O_CREAT | O_APPEND, 0644);
	else if (!ft_strncmp((*list)->content, "<<", 3))
		data->command.input_fd = get_heredoc(filename);
	else if (!ft_strncmp((*list)->content, ">", 2))
		data->command.output_fd = open(filename,
				O_RDWR | O_TRUNC | O_CREAT, 0644);
	else if (!ft_strncmp((*list)->content, "<", 2))
		data->command.input_fd = open(filename, O_RDONLY);
	if (data->command.output_fd < 0 || data->command.input_fd < 0)
	{
		perror(filename);
		free_array(command);
		return (0);
	}
	*list = (*list)->next;
	return (1);
}

// Add one more string to back of 2d char array
// Return 0 if error otherwise 1
static int	array_addback(char ***array, char *str)
{
	char	**tmp;

	if (!*array)
	{
		*array = ft_calloc(2, sizeof(char **));
		if (!*array)
			return (0);
		(*array)[0] = ft_strdup(str);
		if (!(*array)[0])
			return (0);
	}
	else
	{
		tmp = ft_calloc(char_array_len(*array) + 2, sizeof(char *));
		if (!tmp)
			return (0);
		ft_memmove(tmp, *array, char_array_len(*array) * sizeof(char *));
		tmp[char_array_len(*array)] = ft_strdup(str);
		if (!tmp[char_array_len(*array)])
			return (0);
		free(*array);
		*array = tmp;
	}
	return (1);
}

// Split clean input into s_command structure for executor
// Return 0 if error otherwise 1
int	split_into_commands(t_data *data, t_list *clean_input)
{
	char	**command;

	command = NULL;
	while (clean_input)
	{
		if (is_str_redir(clean_input->content))
		{
			if (!get_inout_fd(data, &clean_input, command))
				return (0);
		}
		else if (!ft_strncmp(clean_input->content, "|", 2))
		{
			if (!command || !clean_input->next)
				return (error("syntax error near unexpected token `|'",
						command));
			ft_lstadd_back(data->command.commands, ft_lstnew(command));
			command = NULL;
		}
		else if (!array_addback(&command, clean_input->content))
			return (error(NULL, command));
		clean_input = clean_input->next;
	}
	if (command)
		ft_lstadd_back(data->command.commands, ft_lstnew(command));
	return (1);
}
