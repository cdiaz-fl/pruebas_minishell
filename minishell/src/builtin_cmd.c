/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:44:05 by ioromero          #+#    #+#             */
/*   Updated: 2022/01/26 13:27:10 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo_cmd(t_data *data, char **cmd, int i, int on)
{
	if (cmd[i + 1] && cmd[i + 1][0] == '-' && cmd[i + 1][1] == 'n'
		&& cmd[i + 1][2] == '\0' && ++i)
		on = 1;
	if (data->total_cmds > 1 && data->exect_cmds < data->total_cmds - 1
		&& ++data->forked_cmds)
	{
		if (fork() == 0)
		{
			dup2(data->pfds[data->n_pipes][1], STDOUT_FILENO);
			close_all_fds(data);
			while (cmd[++i] && cmd[i][0] != '|' && printf("%s", cmd[i]))
				if (cmd[i + 1] && cmd[i + 1][0] != '|')
					printf(" ");
			if (!on)
				printf("\n");
			exit(1);	//error management
		}
		return ;
	}
	while (data->cmd_args[++i] && data->cmd_args[i][0] != '|'
				&& printf("%s", data->cmd_args[i]))
			if (data->cmd_args[i + 1] && data->cmd_args[i + 1][0] != '|')
				printf(" ");
		if (!on)
			printf("\n");
}

void	pwd_cmd(t_data *data, char *dir)
{
	errno = 0;
	if (data->total_cmds > 1 && data->exect_cmds < data->total_cmds - 1 &&
			++data->forked_cmds)
	{
		if (fork() == 0)
		{
			dup2(data->pfds[data->n_pipes][1], STDOUT_FILENO);
			close_all_fds(data);
			dir = getcwd(NULL, 0);
			if (errno)
				printf("minishell: %s: %s\n", data->cmd_args[0], strerror(errno));
			else
				printf("%s\n", dir);
			free(dir);
			exit(1);
		}
	}
	else 
	{
		dir = getcwd(NULL, 0);
		if (errno)
			printf("minishell: %s: %s\n", data->cmd_args[0], strerror(errno));
		else
			printf("%s\n", dir);
		free(dir);
	}
}

void	env_cmd(t_data *data)
{
	if (data->total_cmds > 1 && data->exect_cmds < data->total_cmds - 1)
	{
		data->forked_cmds++;
		if (fork() == 0)
		{
			dup2(data->pfds[data->n_pipes][1], STDOUT_FILENO);
			close_all_fds(data);
			print_2d_array(data->env);
			exit(0);
		}
	}
	else
		print_2d_array(data->env);
}

void	is_builtin(t_data *data)
{
	int	i;

	data->blt_exec = 0;
	i = data->current_cmd - 1;
	if ((!data->prompt || !ft_strncmp(data->prompt, "exit", 4)) && printf("exit\n"))
		exit(0);
	while (data->cmd_args[++i] && data->blt_exec == 0)
	{
		if (ft_strncmp_allcases("echo", data->cmd_args[i]) && ++data->blt_exec)
			echo_cmd(data, data->cmd_args, i, 0);
		else if (ft_strncmp_allcases("pwd", data->cmd_args[i]) && ++data->blt_exec)
			pwd_cmd(data, NULL);
		else if (!ft_strncmp("cd", data->cmd_args[i], 2) && ++data->blt_exec)
			cd_switch(data, ++i);
		else if (ft_strncmp_allcases("env", data->cmd_args[i]) && ++data->blt_exec)
			env_cmd(data);
		else if (!ft_strncmp("export", data->cmd_args[i], 6) && ++data->blt_exec)
			export_cmd(data, ++i);
		else if (!ft_strncmp("unset", data->cmd_args[i], 5) && ++data->blt_exec)
			unset_cmd(data, data->cmd_args[++i]);
	}
	if ((!data->prompt || !ft_strncmp(data->prompt, "exit", 4)) && printf("exit\n"))
		exit(0);          //comprobar cuando te pasan el exit mal, con args que no sean números o mal escrito: exitt
	if (data->blt_exec > 0 && ++data->exect_cmds)
		moving_current_cmd(data);
}

void	exec_cmds(t_data *data)
{
	while (data->current_cmd < data->size_args && data->exect_cmds < data->size_args)
	{
		is_builtin(data);
		if (!data->blt_exec)
			launch_cmd(data, -1);
		if (data->total_cmds > 2)
			data->n_pipes++;
	}
	if (data->total_cmds > 1)
	{
		close_all_fds(data);
		free_2d_array((void **)data->pfds);
	}
	while (data->forked_cmds-- > -1)
		wait(0);  //if (status == -1) error management
}

int	check_syntax(char **s, t_data *data)
{
	int	i;
	char	c;

	i = -1;
	c = 0;
	while (s[++i])
	{
		if (s[0][0] == '|')
				c = '|';
		if (s[i][0] == '|')
			if ((s[i + 1] == NULL) || (s[i + 1] && s[i + 1][0] == '|'))
				c = '|';
		if (s[i][0] == '<' || s[i][0] == '>')
		{
			if (s[i + 1] && s[i + 2] && s[i + 1][0] == '<' && s[i + 2][0] == '<')
				c = '<';
			if (s[i + 1] && s[i + 2] && s[i + 1][0] == '>' && s[i + 2][0] == '>')
				c = '>';
		}
		if (c != 0 &&
			printf("minishell: syntax error near unexpected token `%c'\n", c))
			return (1);
	}
	print_debug_2d_array(data->cmd_args);
	unite_redir(data->cmd_args, -1, -1, data);
	print_debug_2d_array(data->cmd_args);
	return (0);
}
