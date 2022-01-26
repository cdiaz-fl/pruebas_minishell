/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:04:19 by ioromero          #+#    #+#             */
/*   Updated: 2022/01/20 13:17:45 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int	ft_strncmp_allcases(char *s1, char *s2)
{
	int	count;
	int	end;

	end = ft_strlen(s1);
	count = 0;
	while (((unsigned char)*s1 == (unsigned char)*s2
			|| (unsigned char)*s1 - (unsigned char)*s2 == 32) && *s1)
	{
		s1++;
		s2++;
		count++;
	}
	if (count == end)
		return (1);
	return (0);
}

char	*trim_s(char *s, char trim_c)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		if (s[i + 1] == trim_c)
		{
			i++;
			j = i + 1;
			while (s[j - 1])
			{
				s[j - 1] = s[j];
				j++;
			}
			s[j - 1] = 0;
		}
		i++;
	}
	return (s);
}

void	print_2d_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
}

void	print_debug_2d_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		printf("%i -> [%s]\n", i, s[i]);
		i++;
	}
}

int	get_2d_size(void **s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	**ft_2d_dup(char **s)
{
	int		i;
	int		size;
	char	**new;

	size = 0;
	while (s[size])
		size++;
	new = (char **)malloc(sizeof(char *) * (size + 1));
	new[size] = NULL;
	i = -1;
	while (++i < size)
		new[i] = ft_strdup(s[i]);
	return (new);
}
