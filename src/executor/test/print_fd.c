/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:53:51 by emomkus           #+#    #+#             */
/*   Updated: 2022/03/18 18:45:51 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipes.h"

int printfd(int	fd)
{
	char	buf[50];
	int		i = 0;
	int		ct = 49;

	while (ct--)
	{
		buf[i] = 0;
		i++;
	}
	read(fd, buf, 49);
	printf("%s\n", buf);
	lseek(fd, 0, SEEK_SET);
	return(0);
}
