/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace_str_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:48:51 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/03 16:50:31 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Return new allocated string old substring length with new substring at idx
// Return NULL if error
char	*str_replace_str_at(char *str, int idx, int length, char *replacement)
{
	char	*new_str;
	char	*tmp;

	if (!str || idx < 0 || length < 0 || !replacement)
		return (NULL);
	if (idx >= (int)ft_strlen(str))
		return (ft_strjoin(str, replacement));
	if (length > (int)ft_strlen(&str[idx]))
		length = (int)ft_strlen(&str[idx]);
	str[idx] = '\0';
	tmp = ft_strjoin(str, replacement);
	if (!tmp)
		return (NULL);
	new_str = ft_strjoin(tmp, &str[idx + length]);
	free(tmp);
	if (!new_str)
		return (NULL);
	return (new_str);
}
