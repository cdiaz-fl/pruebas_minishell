/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:57:08 by ioromero          #+#    #+#             */
/*   Updated: 2022/01/20 13:17:50 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd_cmd(t_data *data, char *dir)
{
	if (!dir)
	{
		printf("minishell: cd: OLDPWD not set\n");
		return ;
	}
	errno = 0;
	chdir(dir);
	if (errno)
		printf("minishell: cd: %s: %s\n", dir, strerror(errno));
	else
		update_env_dir(data, 0);
}

void	cd_switch(t_data *data, int i)
{
	char	*dir;

	//Faltan los flags -L -P y errores como cd -pepe
	dir = ft_strjoin("/Users/", get_env_var(data, "USER"));
	if (data->cmd_args[i] == NULL)
		cd_cmd(data, dir);
	else if (!ft_strncmp(data->cmd_args[i], "-", 1))
		cd_cmd(data, get_env_var(data, "OLDPWD"));
	else if (!ft_strncmp(data->cmd_args[i], "~", 1))
		cd_cmd(data, dir);
	else
		cd_cmd(data, data->cmd_args[i]);
	free (dir);
}
