/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:10:47 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/05 00:11:33 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Return new allocated environment variable value string from name
// Return new allocated empty string if couldn't find
// Return NULL if error
char	*get_env_value(t_list *envp, char **env)
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
