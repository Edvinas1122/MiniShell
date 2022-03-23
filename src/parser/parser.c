/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:43:37 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/23 23:03:55 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	get_redir_input(char *line, t_list **clean_input_list,
	int *start, int *end)
{
	if ((line[*end] == '>' && line[*end + 1] == '>')
		|| (line[*end] == '<' && line[*end + 1] == '<'))
	{
		ft_lstadd_back(clean_input_list,
			ft_lstnew(ft_substr(line, *start, *end - *start + 2)));
		*end += 2;
	}
	else
	{
		ft_lstadd_back(clean_input_list,
			ft_lstnew(ft_substr(line, *start, *end - *start + 1)));
		(*end)++;
	}
}

static void	get_metachar_input(char *line, t_list **clean_input_list,
	int *start, int *end)
{
	if (line[*end] == '>' || line[*end] == '<')
		get_redir_input(line, clean_input_list, start, end);
	else if (line[*end] == '|')
	{
		ft_lstadd_back(clean_input_list,
			ft_lstnew(ft_substr(line, *start, *end - *start + 1)));
		(*end)++;
	}
	else if (line[*end] != '$')
		(*end)++;
	while (line[*end] && ft_isspace(line[*end]))
		(*end)++;
	*start = *end;
}

static void	get_clean_input(char *line, t_list **clean_input_list,
	int *start, int *end)
{
	if (*end != *start)
		ft_lstadd_back(clean_input_list,
			ft_lstnew(ft_substr(line, *start, *end - *start)));
	while (line[*end] && ft_isspace(line[*end]))
		(*end)++;
	*start = *end;
	if (ft_ismetachar(line[*end]))
		get_metachar_input(line, clean_input_list, start, end);
}

static void	get_end_quote(char *line, t_list **clean_input_list,
	int *start, int *end)
{
	char	quote;

	quote = line[*end];
	(*end)++;
	while (line[*end] && quote != line[*end])
		(*end)++;
	if (line[*end])
		(*end)++;
}

// more like lex
void	parser(t_data *data, char *line)
{
	int		start;
	int		end;

	data->clean_input = NULL;
	line = ft_strtrim(line, " \v\t\f\r\n");
	start = 0;
	end = 0;
	while (line[end])
	{
		if (line[end] == '"' || line[end] == '\'')
			get_end_quote(line, &data->clean_input, &start, &end);
		else if ((ft_ismetachar(line[end]) && line[end] != '$')
			|| ft_isspace(line[end]))
			get_clean_input(line, &data->clean_input, &start, &end);
		else
			end++;
	}
	if (start != end)
		get_clean_input(line, &data->clean_input, &start, &end);
}

void	ft_print_a(void *str)
{
	printf("%s\n", (char *)str);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	char	*line;

	data = constructor(envp);
	while (42)
	{
		line = readline("minishell> ");
		if (line == NULL)
			break ;
		parser(data, line);
		if (data->clean_input)
			ft_lstiter(data->clean_input, ft_print_a);
		free(line);
	}
	return (0);
}
