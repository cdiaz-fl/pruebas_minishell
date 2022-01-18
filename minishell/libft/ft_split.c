/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:36:26 by ioromero          #+#    #+#             */
/*   Updated: 2021/10/25 11:18:03 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_error(char **arrays)
{
	size_t	i;

	i = 0;
	while (arrays[i])
	{
		free(arrays[i]);
		i++;
	}
	free(arrays);
	return (0);
}

static size_t	ft_get_nb_strs(char const *s, char c)
{
	size_t	i;
	size_t	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static void	ft_get_nx_str(char **nx_str, size_t *nx_str_len, char c)
{
	size_t	i;

	*nx_str += *nx_str_len;
	*nx_str_len = 0;
	i = 0;
	while (**nx_str && **nx_str == c)
		(*nx_str)++;
	while ((*nx_str)[i])
	{
		if ((*nx_str)[i] == c)
			return ;
		(*nx_str_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arrays;
	char	*nx_str;
	size_t	nx_str_len;
	size_t	i;

	if (!s)
		return (0);
	arrays = (char **)malloc(sizeof(char *) * (ft_get_nb_strs(s, c) + 1));
	if (!arrays)
		return (0);
	i = 0;
	nx_str = (char *)s;
	nx_str_len = 0;
	while (i < ft_get_nb_strs(s, c))
	{
		ft_get_nx_str(&nx_str, &nx_str_len, c);
		arrays[i] = (char *)malloc(sizeof(char) * (nx_str_len + 1));
		if (!arrays[i])
			return (ft_malloc_error(arrays));
		ft_strlcpy(arrays[i], nx_str, nx_str_len + 1);
		i++;
	}
	arrays[i] = 0;
	return (arrays);
}
