/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:24:29 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/10 21:02:53 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../minishell.h"

int		ft_isspace(int c);
char	*str_remove_char_at(char *str, int idx);
char	*str_replace_str_at(char *str, int idx, int length, char *replacement);
t_list	*find_list(t_list *list, char *to_find);
int		is_meta_char(int c);
char	*str_join_space(char *s1, char *s2);
int		char_array_len(char **arr);
void	free_array(char **arr);
int		is_str_redir(char *str);
char	*get_env_value(t_list *envp, char *env);
void	dup2_and_close(int fd_from, int fd_to);
void	handle_parent_signals(void);
void	handle_child_signals(void);
int		is_valid_env(char *str);
int		ft_isnbr(char *nptr);

#endif
