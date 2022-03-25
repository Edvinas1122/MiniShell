/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:58:28 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/28 18:47:04 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	clean_quote(char *input, t_list *input_list)
{
	int		i;
	char	quote;

	quote = 0;
	i = 0;
	while (input[i])
	{
		if ((!quote && (input[i] == '"' || input[i] == '\''))
			|| (quote && input[i] == quote))
		{
			if (!quote && (input[i] == '"' || input[i] == '\''))
				quote = input[i];
			else if (quote && input[i] == quote)
				quote = 0;
			input = str_remove_char_at(input, i);
			// if (!input)
			// 	exit_error();
			free(input_list->content);
			input_list->content = input;
		}
		else
			i++;
	}
}

static char	*get_env_value(t_list *envp, char **env)
{
	char	*tmp;
	t_list	*list;

	if (*env[ft_strlen(*env)] != '=')
	{
		tmp = ft_strjoin(*env, "=");
		if (!tmp)
			return (NULL);
		free(*env);
		*env = tmp;
	}
	list = get_str_list(envp, *env);
	if (!list)
		return (ft_strdup(""));
	return (ft_substr(list->content,
			ft_strlen(*env), ft_strlen(list->content)));
}

static char	*replace_env_str(t_data *data, char *input, int idx)
{
	char	*new_str;
	char	*env;
	char	*tmp;
	int		length;

	idx++;
	length = 0;
	while (input[idx] && (ft_isalpha(input[idx]) || input[idx] == '_'))
	{
		idx++;
		length++;
	}
	env = ft_substr(input, idx - length, length);
	if (!env)
		return (NULL);
	tmp = get_env_value(*data->envp_data.envp_cp, &env);
	free(env);
	if (!tmp)
		return (NULL);
	new_str = str_replace_str_at(input, idx - length - 1, length + 1, tmp);
	free(tmp);
	return (new_str);
}

static void	resolve_env_var(t_data *data, char *input, t_list *input_list)
{
	int		i;
	char	squote;

	squote = 0;
	i = 0;
	while (input[i])
	{
		if (!squote && input[i] == '$')
		{
			input = replace_env_str(data, input, i);
			// if (!input)
			// 	exit_error();
			free(input_list->content);
			input_list->content = input;
		}
		else if (!squote && input[i] == '\'')
			squote = '\'';
		else if (squote && input[i] == '\'')
			squote = 0;
		i++;
	}
}

void	parser(t_data *data)
{
	t_list	*input_list;

	// env in env problem
	// command in env problem
	input_list = data->clean_input;
	while (input_list)
	{
		resolve_env_var(data, input_list->content, input_list);
		clean_quote(input_list->content, input_list);
		input_list = input_list->next;
	}
}
