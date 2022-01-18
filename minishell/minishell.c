/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:16:25 by ioromero          #+#    #+#             */
/*   Updated: 2022/01/18 13:20:02 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	listen_signals(t_data *data)
{
	if (!data->prompt)
		data->prompt = ft_strdup("exit");
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void) argc;
	(void) argv;
	data = (t_data){.env_paths = ft_split(getenv("PATH"), ':'),
		.env = ft_2d_dup(env)};
	//rl_catch_signals = 0;
	while (1)
	{
		data.prompt = readline(BLUE"minishell 👨💻$ "WHITE);
		listen_signals(&data);
		data.cmd_args = split_tokens(data.prompt, "\n\t \v\r\f");
		count_cmds(&data);
		while (++data.current_cmd < data.size_args)
		{
			add_history(data.prompt);
			is_builtin(&data);
			if (!data.blt_exec)
				launch_cmd(&data, -1);
		//print_2d_array(data.cmd_args);
		}
		if (data.total_cmds > 1)
			close_all_fds(&data);
		while (data.system_cmds-- > -1)
			wait(NULL);  //if (status == -1) error management
		free_2d_array((void **)data.pfds);
		free_2d_array((void **)data.cmd_args);
		free(data.prompt);
	}
	free_mem(&data);
	return (0);
}

// git push origin ionmi:dev
