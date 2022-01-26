/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 07:05:02 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2022/01/26 13:11:00 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	count_cmds(t_data *data)
{
	int	i;

	data->total_cmds = 1;
	i = -1;
	while (data->cmd_args[++i])
	{
		if (data->cmd_args[i][0] == '|')
			data->total_cmds++;
	}
	data->current_cmd = 0;
	data->exect_cmds = 0;
	data->n_pipes = 0;
	data->forked_cmds = 0;
	data->size_args = get_2d_size((void **)data->cmd_args);
	create_pipes(data);
	data->redir = NULL;
	count_redir(data, -1, 0, data->cmd_args);
	expand_dollar(data, -1, 1, data->cmd_args);
}

void	create_pipes(t_data *data)
{
	int	i;

	if (data->total_cmds > 1)
	{
		data->pfds = malloc(sizeof(int *) * (data->total_cmds));
		if (!data->pfds)
			exit (1); //error management
		i = -1;
		while (++i < (data->total_cmds - 1))
		{
			data->pfds[i] = malloc(sizeof(int) * 3);
			if (pipe(data->pfds[i]) == -1)
				exit(1); //error management
			data->pfds[i][2] = '\0';
		}
		data->pfds[i] = NULL;
	}
}

void	close_all_fds(t_data *data)
{
	int	i;

	i = -1;
	while (data->pfds[++i])
	{
		close(data->pfds[i][0]);
		close(data->pfds[i][1]);
	}
}
