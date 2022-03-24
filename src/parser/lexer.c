/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:43:37 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/24 17:19:39 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Only those that we need to interpret in project
// Ignore '$' because we get env later in parser
static int	ft_ismetachar(int c)
{
	if (c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

static void	get_clean_input(char *line, t_list **clean_input_list,
	int *start, int *end)
{
	ft_lstadd_back(clean_input_list,
		ft_lstnew(ft_substr(line, *start, *end - *start)));
	while (line[*end] && ft_isspace(line[*end]))
		(*end)++;
	*start = *end;
}

static void	get_metachar_end(char *line, int *end)
{
	if ((line[*end] == '>' && line[*end + 1] == '>')
		|| (line[*end] == '<' && line[*end + 1] == '<'))
		*end += 2;
	else
		*end += 1;
}

static void	get_quote_end(char *line, int *end)
{
	char	quote;

	quote = line[*end];
	(*end)++;
	while (line[*end] && quote != line[*end])
		(*end)++;
	if (line[*end])
		(*end)++;
}

void	lexer(t_data *data, char *line)
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
			get_quote_end(line, &end);
		else if (ft_ismetachar(line[end]))
			get_metachar_end(line, &end);
		else
			end++;
		if (line[start] && (ft_isspace(line[end]) || ft_ismetachar(line[end])
				|| ft_ismetachar(line[end - 1])))
			get_clean_input(line, &data->clean_input, &start, &end);
	}
	if (line[start])
		get_clean_input(line, &data->clean_input, &start, &end);
}
