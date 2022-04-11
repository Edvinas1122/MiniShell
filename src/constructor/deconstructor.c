/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deconstructor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:58:33 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/11 21:36:47 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constructor.h"

void	deconstructor(t_data *data)
{
	ft_lstclear(data->envp_data.envp_cp, free);
	free(data->envp_data.envp_cp);
	ft_lstclear(data->envp_data.envp_empty, free);
	free(data->envp_data.envp_empty);
	if (data->envp_data.pwd)
		free(data->envp_data.pwd);
	if (data->envp_data.old_pwd)
		free(data->envp_data.old_pwd);
	free(data->command.commands);
	free(data);
}
