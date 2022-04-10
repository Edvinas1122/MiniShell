/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:43:37 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/10 21:02:45 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Clean all the quote in the string
// Return 0 if error otherwise 1
static int	clean_quote(char **str)
{
	int		i;
	char	quote;
	char	*tmp;

	quote = 0;
	i = 0;
	while ((*str)[i])
	{
		if ((!quote && ((*str)[i] == '"' || (*str)[i] == '\''))
			|| (quote && (*str)[i] == quote))
		{
			if (!quote && ((*str)[i] == '"' || (*str)[i] == '\''))
				quote = (*str)[i];
			else if (quote && (*str)[i] == quote)
				quote = 0;
			tmp = str_remove_char_at(*str, i);
			free(*str);
			if (!tmp)
				return (0);
			*str = tmp;
		}
		else
			i++;
	}
	return (1);
}

// Split the input from start to end, clean the quote and add it in a new list
// Return 0 if error otherwise 1
static int	get_clean_input(char *line, t_list **clean_input_list,
	int *start, int *end)
{
	char	*content;

	content = ft_substr(line, *start, *end - *start);
	if (!content || !clean_quote(&content))
		return (0);
	ft_lstadd_back(clean_input_list, ft_lstnew(content));
	while (line[*end] && ft_isspace(line[*end]))
		(*end)++;
	*start = *end;
	return (1);
}

// Get the ending index of metachar in line string
static void	get_metachar_end(char *line, int *end)
{
	if ((line[*end] == '>' && line[*end + 1] == '>')
		|| (line[*end] == '<' && line[*end + 1] == '<'))
		*end += 2;
	else
		*end += 1;
}

// Get the ending index of quote in line string
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

// Split the input line into separated string in linked list
// Return 0 if error otherwise 1
int	lexer(char *line, t_list **clean_input)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (line[end])
	{
		if (line[end] == '#')
			ft_bzero(&line[end], ft_strlen(&line[end]));
		if (line[end] == '"' || line[end] == '\'')
			get_quote_end(line, &end);
		else if (is_meta_char(line[end]))
			get_metachar_end(line, &end);
		else
			end++;
		if (line[start] && (ft_isspace(line[end]) || is_meta_char(line[end])
				|| is_meta_char(line[end - 1])))
		{
			if (!get_clean_input(line, clean_input, &start, &end))
				return (0);
		}
	}
	if (line[start] && !get_clean_input(line, clean_input, &start, &end))
		return (0);
	return (1);
}
