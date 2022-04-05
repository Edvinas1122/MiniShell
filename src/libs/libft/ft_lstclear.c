/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 03:35:56 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/04 22:13:26 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*ptr;
// 	t_list	*nexttoptr;

// 	if (lst == NULL)
// 		return ;
// 	nexttoptr = *lst;
// 	while (nexttoptr->next != NULL)
// 	{
// 		ptr = nexttoptr;
// 		nexttoptr = nexttoptr ->next;
// 		ft_lstdelone(ptr, del);
// 	}
// 	ft_lstdelone(nexttoptr, del);
// 	*lst = NULL;
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
