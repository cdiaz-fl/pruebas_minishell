/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:24:48 by ioromero          #+#    #+#             */
/*   Updated: 2022/01/18 12:42:50 by cdiaz-fl         ###   ########.fr       */
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
	char	**env_paths;
	char	**cmd_args;
	int		size_args;
	char	**env;
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
	int		system_cmds;
}	t_data;

/*		minishell.c				*/

/*		utils.c						*/
void	print_2d_array(char **s);
void	print_debug_2d_array(char **s);
char	*trim_s(char *s, char trim_c);
char	*get_env_var(char **env, char *var);
int		ft_strncmp_allcases(char *s1, char *s2);
char	**ft_2d_dup(char **s);
int	get_2d_size(void **s);

/*		split_tokens.c		*/
char	**split_tokens(char const *s, char *c);

/*		builtin_cmd.c			*/
void	is_builtin(t_data *data);

/*		free.c						*/
void	free_2d_array(void **s);
int		free_mem(t_data *data);

/*		pipes.c						*/
void	count_cmds(t_data *data);
void	close_all_fds(t_data *data);

/*		system_cmd.c			*/
void	launch_cmd(t_data *data, int i);

#endif
