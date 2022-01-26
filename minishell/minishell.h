/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:24:48 by ioromero          #+#    #+#             */
/*   Updated: 2022/01/26 13:27:08 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*		includes	*/
# include <term.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
# include <dirent.h>
# include <curses.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include "./libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>

/*		colors		*/
# define BLUE "\e[1;34m"
# define RED "\033[0;31m"
# define WHITE "\033[0;37m"
# define BOLD "\033[1m"
# define NORMAL "\033[0m"

/*		structs		*/
typedef struct s_data
{
/*		env								*/
	char	**env_paths;
	char	**env;
/*		args							*/
	char	**cmd_args;
	int		size_args;
/*		readline					*/
	char	*prompt;
/*			builtin					*/
	int		blt_exec;
/*		pipes							*/
	int		**pfds;
	int		n_pipes;
/*		cmds							*/
	int		total_cmds;
	int		current_cmd;
	int		exect_cmds;
	int		forked_cmds;
/*		redirections			*/
	int		*redir;
}	t_data;

/*		minishell.c				*/

/*		utils.c						*/
void	print_2d_array(char **s);
void	print_debug_2d_array(char **s);
char	*trim_s(char *s, char trim_c);
int		ft_strncmp_allcases(char *s1, char *s2);
char	**ft_2d_dup(char **s);
int	get_2d_size(void **s);

/*		split_tokens.c		*/
char	**split_tokens(char const *s, char *c);

/*		builtin_cmd.c			*/
void	is_builtin(t_data *data);
void	exec_cmds(t_data *data);
int		check_syntax(char **s, t_data *data);

/*		free.c						*/
void	free_2d_array(void **s);
int		free_mem(t_data *data);

/*		pipes.c						*/
void	count_cmds(t_data *data);
void	create_pipes(t_data *data);
void	close_all_fds(t_data *data);

/*		system_cmd.c			*/
void	launch_cmd(t_data *data, int i);
void	moving_current_cmd(t_data *data);

/*		debug.c						*/
void	print_fds_debug(char *joined, char **cmd, char c, int pipes);

/*		signals.c					*/
void	listen_signals(t_data *data);

/*			env.c						*/
void	update_env_dir(t_data *data, int i);
void	export_cmd(t_data *data, int j);
void	unset_cmd(t_data *data, char *args);
char	*get_env_var(t_data *data, char *var);

/*			cd.c						*/
void	cd_switch(t_data *data, int i);

/*			expand.c				*/
void	expand_dollar(t_data *data, int i, int size, char **s);
void	unite_redir(char **s, int i, int j, t_data *data);
void	count_redir(t_data *data, int i, int size, char **s);
int		search_word(char *word, char **env);

#endif
