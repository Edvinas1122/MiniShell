/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_resolver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:25:13 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/05 00:38:04 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Return new allocated that replaces environment variable name with value
// Environment variable name starts at idx of $
// Return NULL if error
static char	*replace_str_env(t_data *data, char *input, int idx)
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
	tmp = get_env_value(*data->envp_data.envp_cp, env);
	free(env);
	if (!tmp)
		return (NULL);
	new_str = str_replace_str_at(input, idx - length - 1, length + 1, tmp);
	free(tmp);
	return (new_str);
}

// Resolve all environment variable in the string
// Return 0 if error otherwise 1
int	env_resolver(t_data *data, char **input)
{
	int		i;
	char	quote;
	char	*tmp;

	quote = 0;
	i = 0;
	while ((*input)[i])
	{
		if ((!quote || quote == '"') && (*input)[i] == '$')
		{
			tmp = replace_str_env(data, *input, i);
			if (!tmp)
				return (0);
			free(*input);
			*input = tmp;
			if (!(*input)[i])
				break ;
		}
		else if (!quote && ((*input)[i] == '\'' || (*input)[i] == '"'))
			quote = (*input)[i];
		else if (quote && (*input)[i] == quote)
			quote = 0;
		i++;
	}
	return (1);
}
