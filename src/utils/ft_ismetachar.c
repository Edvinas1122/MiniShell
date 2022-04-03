/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismetachar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:38:19 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/03 15:38:25 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Only those that we need to interpret in project
int	ft_ismetachar(int c)
{
	if (c == '>' || c == '<' || c == '|' || c == '$')
		return (1);
	return (0);
}
