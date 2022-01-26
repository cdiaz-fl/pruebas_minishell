/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 07:13:54 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2022/01/26 13:27:01 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unite_redir(char **s, int i, int j, t_data *data)
{
	int	new_size;
	char	**new;

	new_size = get_2d_size((void **)data->cmd_args);
	while (s[++i])
		if ((s[i][0] == '<' && s[i + 1] && s[i + 1][0] == '<')
			|| (s[i][0] == '>' && s[i + 1] && s[i + 1][0] == '>'))
			new_size--;
	if (new_size == get_2d_size((void **)data->cmd_args))
		return ;
	new = malloc(sizeof(char *) * new_size + 1);
	i = -1;
	while (++j < new_size && s[++i])
	{
		if (s[i][0] == '<' && s[i + 1] && s[i + 1][0] == '<' && ++i)
			new[j] = ft_strdup("<<\0");
		else if (s[i][0] == '>' && s[i + 1] && s[i + 1][0] == '>' && ++i)
			new[j] = ft_strdup(">>\0");
		else
			new[j] = ft_strdup(s[i]);
	}
	new[j] = NULL;
	free_2d_array((void **)data->cmd_args);
	data->cmd_args = new;
}

void	count_redir(t_data *data, int i, int size, char **s)
{
	int	j;

	while (s[++i])
	{
		if (ft_strlen(s[i]) < 2 && (s[i][0] == '<' || s[i][0] == '>'))
			size++;
		else if (ft_strlen(s[i]) < 3 && (s[i][0] == '<' || s[i][0] == '>')
			&& (s[i][1] == '<' || s[i][1] == '>'))
			size++;
	}
	if (size == 0)
		return ;
	data->redir = malloc(sizeof(int) * (size + 1));
	j = -1;
	i = -1;
	while (s[++i])
	{
		if (ft_strlen(s[i]) < 2 && (s[i][0] == '<' || s[i][0] == '>')
			&& ++j > -1)
			data->redir[j] = i;
		else if (ft_strlen(s[i]) < 3 && (s[i][0] == '<' || s[i][0] == '>')
			&& (s[i][1] == '<' || s[i][1] == '>') && ++j > -1)
			data->redir[j] = i;
	}
	data->redir[j] = '\0';
}

char	*replace_exp_value(char *s, int size, char *value, int size_new)
{
	char	*new;
	int 	i;

	i = 0;
	while (s[i] && s[i] != '$')
		i++;
	printf("i %d\n", i);
	printf("len s %d\n", (int)ft_strlen(s));
	printf("size %d\n", size);
	new = malloc(sizeof(char) * ((int)ft_strlen(s) - size + size_new + 1));
	new = NULL;
	ft_strlcat(new, s, i);
	printf("first [%s]\n", new);
	ft_strlcat(new, value, size_new);
	printf("second [%s]\n", new);
	i += size;
	ft_strlcat(new, s + i, ft_strlen(s) - i);
	printf("third [%s]\n", new);
	free(s);
	return (new);
}

void	expand_dollar(t_data *data, int i, int j, char **s)
{
	char	*word;
	char	*value;
	char	*crop_word;

	while (s[++i])
	{
		word = ft_strchr(s[i], '$');
		while (word !=  NULL)
		{
			while (word[j] && word[j] != '\'' && word[j] != '\"' && word[j] != ' '
				&& word[j] != '$')
				++j;
			crop_word = ++word;
			if (j > 1)
			{
				printf("crop [%s]\n", crop_word);
				ft_strlcat(crop_word, word, j);
				value = get_env_var(data, crop_word);
				printf("la palabra es [%s]\n", value);
				if (value)
					s[i] = replace_exp_value(s[i], (int)ft_strlen(--word), value, \
					(int)ft_strlen(value));
				word = ft_strchr(s[i], '$');
			}
		}
	}
}

