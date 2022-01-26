/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:50:46 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2022/01/25 07:06:47 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_parts(char const *s, char *c, int count, int i)
{
	while (s[i])
	{
		while (s[i] && ft_strchr(c, s[i]) != NULL)
			i++;
		count++;
		while (s[i] && ft_strchr(c, s[i]) == NULL)
		{
			if ((s[i] == '"' || s[i] == '\''))
			{
				if (s[i] == '"' && ++i)
					while (s[i] && s[i] != '"')
						i++;
				else if (++i)
					while (s[i] && s[i] != '\'')
						i++;
			}
			if ((s[i] == '|' || s[i] == '<' || s[i] == '>') && ++count && ++i)
				break ;
			i++;
		}
	}
	return (count);
}

static char	**clean(char **p, size_t count)
{
	size_t	i;

	if (p)
	{
		i = 0;
		while (i < count)
		{
			if (p[i] != NULL)
				free(p[i]);
			i++;
		}
		free (p);
	}
	return (NULL);
}

static char	*second(char const *s, char *c, int f_len, int i)
{
	char	*str;

	while (s[i] && ft_strchr(c, s[i]) == NULL && ft_strchr("|<>", s[i]) == NULL)
	{
		f_len = -1;
		if (s[i] && s[i] == '"' && ++i)
			while (s[i] && s[i] != '"')
				i++;
		else if (s[i] && s[i] == 39 && ++i)
			while (s[i] && s[i] != 39)
				i++;
		i++;
	}
	if ((s[i] == '|' || s[i] == '<' || s[i] == '>') && f_len != -1)
		i = 1;
	f_len = i;
	str = (char *) malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < f_len)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

static char	**first(char const *s, char *c, char **all)
{
	int	i;
	int	aux;

	i = 0;
	while (*s)
	{
		while (*s && ft_strchr(c, *s) != NULL)
			s++;
		if (*s)
		{
			all[i] = second(s, c, 0, 0);
			if (!all[i])
				return (clean(all, i));
			i++;
			aux = 0;
			while (*s && aux < (int)ft_strlen(all[i - 1]) && ++aux)
				s++;
		}
	}
	all[i] = NULL;
	return (all);
}

char	**split_tokens(char const *s, char *c)
{
	int		parts;
	char	**all;

	if (!s)
		return (NULL);
	parts = count_parts(s, c, 0, 0);
	all = (char **) malloc((parts + 1) * sizeof(char *));
	if (!all)
		return (NULL);
	all = first(s, c, all);
	return (all);
}
