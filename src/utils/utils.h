/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:24:29 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/04 22:00:27 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../minishell.h"

int		ft_isspace(int c);
char	*str_remove_char_at(char *str, int idx);
char	*str_replace_str_at(char *str, int idx, int length, char *replacement);
t_list	*find_list(t_list *list, char *to_find);
int		ft_ismetachar(int c);
char	*ft_strjoinspace(char *s1, char *s2);
int		chararraylen(char **arr);
void	free_array(char **arr);
int		is_str_redir(char *str);

#endif
