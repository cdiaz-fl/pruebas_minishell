/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:01:16 by ioromero          #+#    #+#             */
/*   Updated: 2022/01/20 13:28:56 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_pwd(t_data *data)
{
	char	*dir;

	errno = 0;
	dir = getcwd(NULL, 0);
	if (errno)
		printf("minishell: %s: %s\n", data->cmd_args[0],
			strerror(errno));
	else
		return (dir);
	return (0);
}

char	*get_env_var(t_data *data, char *var)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if (!ft_strncmp(var, data->env[i], ft_strlen(var)))
			return (data->env[i] + ft_strlen(var) + 1);
		i++;
	}
	return (NULL);
}

void	update_env_dir(t_data *data, int i)
{
	char	*dir;

	while (data->env[i])
	{
		if (!ft_strncmp("OLDPWD", data->env[i++], 6))
		{
			free(data->env[i - 1]);
			data->env[i - 1] = ft_strjoin("OLDPWD=", get_env_var(data, "PWD"));
		}
	}
	if (!get_env_var(data, "OLDPWD"))
		data->env[i - 1] = ft_strjoin("OLDPWD=", get_env_var(data, "PWD"));
	i = 0;
	while (data->env[i])
	{
		if (!ft_strncmp("PWD", data->env[i++], 3))
		{
			free(data->env[i - 1]);
			data->env[i - 1] = ft_strjoin("PWD=", get_env_var(data, "PWD"));
			dir = get_pwd(data);
			if (dir)
				data->env[i - 1] = ft_strjoin("PWD=", dir);
			free(dir);
		}
	}
}

void	export_cmd(t_data *data, int j)
{
	//contemplar cuando no hacen bien la sintaxis del export: export===PEPE
	char	**new_env;
	int		i;

	errno = 0;
	i = 0;
	while (data->env[i])
		i++;
	i++;
	new_env = malloc(sizeof(char *) * (i + 1));
	/*
	if (!new_env)
		printf("minishell: %s: %s: %s\n", data->cmd_args[i -1],
			data->cmd_args[i], strerror(errno));
	*/
	i = -1;
	while (data->env[++i])
		new_env[i] = ft_strdup(data->env[i]);
	new_env[i] = ft_strdup(data->cmd_args[j]);
	new_env[i + 1] = NULL;
	free_2d_array((void **)data->env);
	data->env = new_env;
	print_2d_array(data->env);
}

void	unset_cmd(t_data *data, char *args)
{
	char	**new_env;
	int		i;
	int		j;

	errno = 0;
	i = 0;
	while (data->env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 1));
	i = -1;
	j = -1;
	while (++j > -1 && data->env && data->env[++i])
	{
		if (!ft_strncmp(data->env[i], args, ft_strlen(args)))
			i++;
		if (data->env[i])
		{
			new_env[j] = ft_strdup(data->env[i]);
		}
	}
	new_env[j] = NULL;
	free_2d_array((void **)data->env);
	data->env = new_env;
}
