/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:57:38 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/12 18:23:30 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	cd_to_home(t_data *data)
{
	char	*home_dir;

	home_dir = get_env_value(*data->envp_data.envp_cp, "HOME");
	if (home_dir[0] == '\0')
	{
		ft_putendl_fd("cd: HOME not set\n", STDERR_FILENO);
		free(home_dir);
		return (EXIT_FAILURE);
	}
	change_dir(data, home_dir);
	free(home_dir);
	return (EXIT_SUCCESS);
}

// static t_list	**construct_build_list(char **array)
// {
// 	t_list	**list;
// 	int		i;

// 	list = malloc(sizeof(t_list *));
// 	i = 0;
// 	while(array[i])
// 	{
// 		ft_lstadd_back(list, ft_lstnew(array[i]));
// 		i++;
// 	}
// 	return(list);
// }

// static void	delete_last_list(t_list **list)
// {
// 	t_list	*list_el;
// 	t_list	*tmp;

// 	list_el = *list;
// 	while(list_el->next)
// 	{
// 		tmp = list_el;
// 		list_el = list_el->next;
// 	}
// 	free(list_el->content);
// 	free(list_el);
// 	tmp->next = NULL;
// }

// static char *lst_to_str(t_list **list)
// {
// 	t_list	*list_el;
// 	char	*str;
// 	char	*tmp;

// 	list_el = *list;
// 	str = ft_strdup(list_el->content);
// 	list_el = list_el->next;
// 	while(list_el)
// 	{
// 		tmp = str;
// 		str = ft_strjoin(tmp, list_el->content);
// 		list_el = list_el->next;
// 		free(tmp);
// 	}
// 	return(str);
// }

// static void	cd_to_relative(t_data *data, char **argv)
// {
// 	int		i;
// 	char	**path_array;
// 	t_list	**build_path;

	
// 	build_path = construct_build_list(ft_split(data->envp_data.pwd, '/'));
// 	ft_putstr_fd(lst_to_str(build_path), 1);
// 	write(1, "\n", 1);
// 	path_array = ft_split(argv[1], '/');
// 	i = 0;
// 	while(path_array[i])
// 	{
// 		ft_putstr_fd(path_array[i], 1);
// 		write(1, "\n", 1);
// 		if (!ft_strncmp(path_array[i], "..", 3))
// 			delete_last_list(build_path);
// 		else
// 			ft_lstadd_back(build_path, ft_lstnew(path_array[i])); //add to the last element
// 		i++;
// 		ft_putstr_fd(lst_to_str(build_path), 1);
// 		write(1, "\n", 1);
// 	}
// 	ft_putstr_fd(lst_to_str(build_path), 1);
// 	write(1, "\n", 1);
// 	// free list and array;
// }

// static void	print_cwd(void)
// {
// 	char	*cwd;

// 	cwd = get_cwd();
// 	ft_putstr_fd(cwd, 1);
// 	write(1, "\n", 1);
// 	free(cwd);
// }

/* The CD builtin */
/* Does not implament symlinks */
int	execute_cd(t_data *data, char **argv)
{
	// path_str_of_relative(data, argv);
	if (argv[1] == NULL)
		return (cd_to_home(data));
	else
		return (change_dir(data, argv[1]));
	return (EXIT_SUCCESS);
}
