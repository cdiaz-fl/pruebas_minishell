/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:42:57 by ioromero          #+#    #+#             */
/*   Updated: 2021/10/07 11:02:26 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*aux;
	size_t	j;
	size_t	i;

	aux = (char *)haystack;
	j = 0;
	if (*needle == 0)
		return (aux);
	while (*aux && j <= len)
	{
		i = 0;
		while (aux[i] == needle[i])
		{
			if (i + 1 == ft_strlen(needle) && j + i < len)
				return (aux);
			i++;
		}
		aux++;
		j++;
	}
	return (0);
}
