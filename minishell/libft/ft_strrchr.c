/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:34:02 by ioromero          #+#    #+#             */
/*   Updated: 2021/06/01 12:17:39 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*aux;
	size_t	i;

	aux = (char *)s;
	i = 0;
	while (*aux)
	{
		i++;
		aux++;
	}
	if (*aux == c)
		return (aux);
	aux--;
	while (*aux && i-- > 0)
	{
		if (*aux == c)
			return (aux);
		aux--;
	}
	return (0);
}
