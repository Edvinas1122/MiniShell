/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:45:59 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/03 21:49:50 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoinspace(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = ft_calloc(s1_len + s2_len + 2, sizeof(char));
	if (str)
	{
		ft_strlcpy(str, s1, s1_len + 1);
		ft_strlcat(str, " ", s1_len + 2);
		ft_strlcat(str, s2, s1_len + s2_len + 1);
	}
	return (str);
}
