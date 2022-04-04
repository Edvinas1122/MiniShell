/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_meta_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:38:19 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/04 23:17:59 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Only those that we need to interpret in project
int	is_meta_char(int c)
{
	if (c == '>' || c == '<' || c == '|' || c == '$')
		return (1);
	return (0);
}
