/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:16:25 by ioromero          #+#    #+#             */
/*   Updated: 2022/01/25 18:30:19 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**dup_env(char **s)
{
	int		i;
	int		size;
	char	**new;
	int		j;

	size = 0;
	while (s[size])
		size++;
	new = (char **)malloc(sizeof(char *) * (size));
	new[size - 1] = NULL;
	i = 0;
	j = 0;
	while (i < size)
	{
		if (!ft_strncmp(s[i], "OLDPWD", 6))
		{
			i++;
			j++;
			continue ;
		}
		new[i - j] = ft_strdup(s[i]);
		i++;
	}
	return (new);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void) argc;
	(void) argv;
	data = (t_data){.env_paths = ft_split(getenv("PATH"), ':'),
		.env = dup_env(env)};
	// rl_catch_signals = 0;
	while (1)
	{
		data.prompt = readline(BLUE"minishell 👨💻$ "WHITE);
		listen_signals(&data);
		add_history(data.prompt);
		data.cmd_args = split_tokens(data.prompt, "\n\t \v\r\f");
		if (!check_syntax(data.cmd_args, &data))
		{
			count_cmds(&data);
			exec_cmds(&data);
		}
		free_2d_array((void **)data.cmd_args);
		free(data.prompt);
		free(data.redir);
	}
	free_mem(&data);
	return (0);
}

// git push origin ionmi:dev
