/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_splitter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:15:16 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/04 22:52:58 by cthien-h         ###   ########.fr       */
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
	if (!ft_strncmp((*list)->content, ">", 2))
		data->command.output_fd = open(filename,
				O_RDWR | O_TRUNC | O_CREAT, 0644);
	else if (!ft_strncmp((*list)->content, ">>", 3))
		data->command.output_fd = open(filename,
				O_RDWR | O_TRUNC | O_APPEND, 0644);
	else if (!ft_strncmp((*list)->content, "<", 2))
		data->command.input_fd = open(filename, O_RDONLY);
	else if (!ft_strncmp((*list)->content, "<<", 3))
		perror("unimplement");
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
		tmp = ft_calloc(chararraylen(*array) + 2, sizeof(char *));
		if (!tmp)
			return (0);
		ft_memmove(tmp, *array, chararraylen(*array) * sizeof(char *));
		tmp[chararraylen(*array)] = ft_strdup(str);
		if (!tmp[chararraylen(*array)])
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
