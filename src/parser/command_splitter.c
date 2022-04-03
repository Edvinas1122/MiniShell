/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_splitter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:15:16 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/04 00:34:23 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Error handler
static int	error(char *err)
{
	if (err)
		ft_putendl_fd(err, 2);
	else
		perror(err);
	return (0);
}

// Get new allocated string redirection filename
// filename is NULL if couldn't find
// Return 0 if not redirection otherwise 1
static int	get_io_filename(t_list *list, char **filename)
{
	*filename = NULL;
	if (ft_strncmp(list->content, ">", 2)
		&& ft_strncmp(list->content, ">>", 3)
		&& ft_strncmp(list->content, "<", 2)
		&& ft_strncmp(list->content, "<<", 3))
		return (0);
	if (!list->next)
		return (1);
	*filename = list->next->content;
	return (1);
}

// Get input/ouput fd if redirection, if not redirection return 1 to continue
// Return 0 if error otherwise 1
// TODO: discuss how to handle << heredoc
static int	get_inout_fd(t_data *data, t_list **list)
{
	char	*filename;

	if (!get_io_filename(*list, &filename))
		return (1);
	if (!filename && ft_strncmp((*list)->content, "<<", 3))
		return (error("syntax error near unexpected token `newline'"));
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
		free(filename);
		return (0);
	}
	*list = (*list)->next->next;
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
	t_list	*list;
	char	**command;

	command = NULL;
	list = clean_input;
	while (list)
	{
		if (!ft_strncmp(list->content, "|", 2))
		{
			if (!command)
				return (error("syntax error near unexpected token `|'"));
			ft_lstadd_back(data->command.commands, ft_lstnew(command));
			command = NULL;
		}
		else if (!get_inout_fd(data, &list))
			return (0);
		else if (!array_addback(&command, list->content))
			return (error(NULL));
		list = list->next;
	}
	return (1);
}
