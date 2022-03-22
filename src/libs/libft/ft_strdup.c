/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:16:39 by emomkus           #+#    #+#             */
/*   Updated: 2022/03/22 12:15:24 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* Dublicates string allocates and returns pointer to allocated dublicated str
*/
char	*ft_strdup(const char *s)
{
	char	*snew;
	int		i;

	snew = malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	while (s[i])
	{
		snew[i] = s[i];
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
