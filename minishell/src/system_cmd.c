/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 08:04:16 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2022/01/25 18:30:25 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	child_function(t_data *data, char **cmd, char *joined)
{
	if (data->total_cmds == 1)
		execve(joined, data->cmd_args, data->env);
	else if (data->exect_cmds == (data->total_cmds - 1))
	{
		//print_fds_debug(joined, cmd, '3', data->n_pipes);
		dup2(data->pfds[data->total_cmds - 2][0], STDIN_FILENO);
	}
	else if (data->exect_cmds == 0)
	{
		//print_fds_debug(joined, cmd, '1', data->n_pipes);
		dup2(data->pfds[0][1], STDOUT_FILENO);
	}
	else
	{
		//print_fds_debug(joined, cmd, '2', data->n_pipes);
		dup2(data->pfds[data->n_pipes - 1][0], STDIN_FILENO);
		dup2(data->pfds[data->n_pipes][1], STDOUT_FILENO);
	}
	close_all_fds(data);
	execve(joined, cmd, data->env);
	exit(1);	//error management
}

char	**cut_2d_array(t_data *data, char **s) 
{
	char	**result;
	int		i;
	int		start;
	int		end;

	start = data->current_cmd;
	i = start;
	while (s[i] && s[i][0] != '|')
		i++;
	end = i;
	result = malloc(sizeof(char *) * ((end - start) + 1));
	if (!result)	//error management
		printf("error \n");
	i = -1;
	while (++i > -1 && start < end && s[start])
	{
		result[i] = ft_strdup(s[start]);
		start++;
	}
	result[i] = NULL;
	//print_debug_2d_array(result);
	return (result);
}

void	moving_current_cmd(t_data *data)
{
	int	i;

	data->current_cmd++;
	i = -1;
	while (++i < data->size_args && data->cmd_args[data->current_cmd])
	{
		if (data->cmd_args[data->current_cmd - 1][0] != '|')
			data->current_cmd++;
	}
}

void	launch_cmd(t_data *data, int i)
{
	char	**cmd;
	char	*joined;
	char	*tmp;

	cmd = NULL;
	while (data->env_paths[++i])
	{
		tmp = ft_strjoin(data->env_paths[i], "/");
		joined = ft_strjoin(tmp, data->cmd_args[data->current_cmd]);
		free(tmp);
		if (!access(joined, X_OK))
		{
			if (data->total_cmds > 1)
				cmd = cut_2d_array(data, data->cmd_args);
			if (fork() == 0)
				child_function(data, cmd, joined);
			if (cmd)
				free_2d_array((void **)cmd);
			data->exect_cmds++;
			data->forked_cmds++;
			moving_current_cmd(data);
			return ;
		}
		free(joined);
	}
	if (data->cmd_args[data->current_cmd][0] != '|')
	{
		data->exect_cmds++;
		printf("bash: command not found: \n"); //fix error message
		moving_current_cmd(data);
	}
}
