/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:55:43 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/11 20:07:41 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* Returns pointer to malloced string - system current working dirrectory */
char	*get_cwd(void)
{
	char	*cwd;
	char	*buf;
	int		size;

	cwd = NULL;
	size = 1;
	while (!cwd)
	{
		buf = malloc(size);
		cwd = getcwd(buf, size);
		if (!cwd)
			free(buf);
		size++;
	}
	return (cwd);
}