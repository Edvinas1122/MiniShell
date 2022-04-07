/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:57:38 by emomkus           #+#    #+#             */
/*   Updated: 2022/04/07 11:42:06 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	cwd_update(t_envp_data env_data)
{
	
}

static void	cd_to_home(t_data *data)
{
	char	*home_dir;
	char	*tmp;

	tmp = get_env_value(*data->envp_data.envp_cp, "HOME");
	home_dir = ft_strtrim(tmp, "HOME=");
	free(tmp);
	if (chdir(home_dir))
	{
		perror();
	}
	
}

/* Count "../" in a string */
static int	back_track(char **argv)
{
	int	ct;

	ct = 0;
	
	return (ct);
}

/* The CD builtin */
int	execute_cd(char **argv, t_data *data)
{
	int	i;

	i = 0;
	if (argv[1] == NULL)
		cd_to_home(data);
	while (argv[1][i])
	{
		if (ft_strncmp(&argv[1][i], "..", 3))
			back_track();
		else if ()
		i++;
	}
	exit(EXIT_SUCCESS);
}
