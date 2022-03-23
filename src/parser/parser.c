/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:43:37 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/23 19:43:51 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	get_redir_input()
{

}

static void	get_metachar_input(char *line, t_list **clean_input_list,
	int *start, int *end)
{
	if (line[*end] == '>' || line[*end] == '<')
		get_redir_input();
	else if (line[*end] == '|')
	{
		ft_lstadd_back(clean_input_list,
			ft_lstnew(ft_substr(line, *start, *end - *start + 1)));
		*end++;
	}
	else
		*end++;
}

static void	get_clean_input(char *line, t_list **clean_input_list,
	int *start, int *end)
{
	ft_lstadd_back(clean_input_list,
		ft_lstnew(ft_substr(line, *start, *end - *start)));
	*start = *end;
}

static void	get_end_quote(char *line, t_list **clean_input_list,
	int *start, int *end)
{
	char	quote;

	quote = line[*end++];
	while (quote != line[*end])
	{
		if (line[*end + 1] == '\0')
		{
			get_clean_input(line, clean_input_list, start, end);
			break ;
		}
		*end++;
	}
}

// more like lex
void	parser(t_data *data, char *line)
{
	t_list	*clean_input_list;
	int		start;
	int		end;

	line = ft_strtrim(line, " \v\t\f\r\n");
	start = 0;
	end = 0;
	while (line[end])
	{
		if (line[end] == '"' || line[end] == '\'')
			get_end_quote(line, &clean_input_list, &start, &end);
		else if (ft_ismetachar(line[end]) || ft_isspace(line[end]))
		{
			if (line[end] == '$')
			{
				end++;
				continue ;
			}
			get_clean_input(line, &clean_input_list, &start, &end);
			while (ft_isspace(line[end]))
				end++;
			if (ft_ismetachar(line[end]))
				get_metachar_input();
		}
		else
			end++;
	}
}
