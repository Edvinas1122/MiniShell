/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:10:47 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/09 18:32:25 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Return new allocated environment variable value string from name
// Return new allocated empty string if couldn't find
// Return NULL if error
char	*get_env_value(t_list *envp, char *env)
{
	char	*tmp;
	t_list	*list;
	int		value_start;
	int		to_free;

	to_free = 0;
	if (env[ft_strlen(env)] != '=')
	{
		tmp = ft_strjoin(env, "=");
		if (!tmp)
			return (NULL);
		env = tmp;
		to_free = 1;
	}
	value_start = ft_strlen(env);
	list = find_list(envp, env, 0);
	if (to_free)
		free(env);
	if (!list)
		return (ft_strdup(""));
	return (ft_substr(list->content,
			value_start, ft_strlen(list->content)));
}
