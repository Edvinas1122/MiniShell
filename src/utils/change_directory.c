/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:48:15 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/08 10:40:15 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	change_dir(t_data *data, char *dir)
{
	(void)data;
	// free(data->envp_data.old_pwd);
	// data->envp_data.old_pwd = data->envp_data.pwd;
	// data->envp_data.pwd = dir;
	return(chdir(dir));
}