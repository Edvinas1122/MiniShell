/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_resolver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:25:13 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/03 19:50:28 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Return new allocated environment variable value string from name
// Return new allocated empty string if couldn't find
// Return NULL if error
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
	list = find_list(envp, *env);
	if (!list)
		return (ft_strdup(""));
	return (ft_substr(list->content,
			ft_strlen(*env), ft_strlen(list->content)));
}

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
	tmp = get_env_value(*data->envp_data.envp_cp, &env);
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
	char	squote;
	char	*tmp;

	squote = 0;
	i = 0;
	while ((*input)[i])
	{
		if (!squote && (*input)[i] == '$')
		{
			tmp = replace_str_env(data, *input, i);
			if (!tmp)
				return (0);
			free(*input);
			*input = tmp;
			if (!(*input)[i])
				break ;
		}
		else if (!squote && (*input)[i] == '\'')
			squote = '\'';
		else if (squote && (*input)[i] == '\'')
			squote = 0;
		i++;
	}
	return (1);
}
