/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:58:46 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/04 22:15:27 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Return 1 if string is redirection
int	is_str_redir(char *str)
{
	if (!ft_strncmp(str, ">", 2)
		|| !ft_strncmp(str, ">>", 3)
		|| !ft_strncmp(str, "<", 2)
		|| !ft_strncmp(str, "<<", 3))
		return (1);
	return (0);
}
