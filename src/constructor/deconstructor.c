/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deconstructor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:58:33 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/04 20:46:08 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constructor.h"

void	deconstructor(t_data *data)
{
	ft_lstclear(data->envp_data.envp_cp, free);
	free(data->envp_data.envp_cp);
	free(data->command.commands);
	free(data);
}
