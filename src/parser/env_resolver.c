/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_resolver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:25:13 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/08 19:59:22 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Get PWD value from environment if exists
// Otherwise try to get PWD from memory
// Return NULL if error
static char	*get_pwd(t_envp_data envp_data)
{
	char	*pwd;

	pwd = get_env_value(*envp_data.envp_cp, "PWD");
	if (!pwd)
		return (NULL);
	if (!ft_strlen(pwd))
	{
		if (!envp_data.pwd)
			return (ft_strdup(""));
		pwd = ft_strdup(envp_data.pwd);
		if (!pwd)
			return (NULL);
	}
	return (pwd);
}

// Find environment and return its value in envp
// In special case, it gets from memory (such as PWD)
static char	*resolving_env(t_envp_data envp_data, char *env_name)
{
	if (!ft_strncmp(env_name, "PWD", 4))
		return (get_pwd(envp_data));
	else
		return (get_env_value(envp_data.envp_cp, env_name));
}

// Return new allocated that replaces environment variable name with value
// Environment variable name starts at idx of $
// Return NULL if error
static char	*replace_str_env(t_data *data, char *input, int idx)
{
	char	*new_str;
	char	*env_value;
	int		length;

	length = 0;
	while (input[idx] && (ft_isalpha(input[idx])
			|| ft_isdigit(input[idx]) || input[idx] == '_'))
	{
		idx++;
		length++;
		if (!(length - 1) && ft_isdigit(input[idx - 1]))
			break ;
	}
	new_str = ft_substr(input, idx - length, length);
	if (!new_str)
		return (NULL);
	env_value = resolving_env(data->envp_data, new_str);
	free(new_str);
	if (!env_value)
		return (NULL);
	new_str = str_replace_str_at(input, idx - length - 1, length + 1,
			env_value);
	free(env_value);
	return (new_str);
}

// Check if env is a special environment variable and return it
// Otherwise return env from normal envp
static char	*check_and_get_env(t_data *data, char *input, int idx)
{
	char	*exit_status;
	char	*ret;

	idx++;
	if (input[idx] && input[idx] == '?')
	{
		exit_status = ft_itoa(data->envp_data.exit_status);
		ret = str_replace_str_at(input, idx - 1, 2, exit_status);
		free(exit_status);
		return (ret);
	}
	else
		return (replace_str_env(data, input, idx));
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
			tmp = check_and_get_env(data, *input, i);
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
