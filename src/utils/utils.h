/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:24:29 by cthien-h          #+#    #+#             */
/*   Updated: 2022/04/11 23:20:16 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../minishell.h"

typedef struct s_envp_data	t_envp_data;

int		ft_isspace(int c);
char	*str_remove_char_at(char *str, int idx);
char	*str_replace_str_at(char *str, int idx, int length, char *replacement);
t_list	*find_list(t_list *list, char *to_find, int exact_str);
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
char	*get_cwd(void);
int		change_dir(t_data *data, char *dir);
void	find_delete_list(t_list **list, char *match, void (*del)(void *));
int		export_print_alone(t_envp_data envp_data);

#endif
