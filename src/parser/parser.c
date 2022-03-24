/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:58:28 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/25 18:06:09 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	clean_input(t_list *input_list)
{
	int		i;
	char	*str;
	char	quote;

	quote = 0;
	while (input_list)
	{
		str = input_list->content;
		i = 0;
		while (str[i])
		{
			if (!quote && (str[i] == '"' || str[i] == '\''))
			{
				quote = str[i];
				str = str_remove_char_at(str, i);
				free(input_list->content);
				input_list->content = str;
			}
			if (str[i] == '$' && quote != '\'')
			{
				str = str_get_env(str, i);
			}
			i++;
		}
		input_list = input_list->next;
	}
}

void	parser(t_data *data)
{
	clean_input(data->clean_input);
}
