/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:18:14 by ioromero          #+#    #+#             */
/*   Updated: 2022/01/12 16:51:11 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*aux;

	aux = (char *)s;
	while (*aux)
	{
		if (*aux == c)
			return (aux);
		aux++;
	}
	if (*aux == c)
		return (aux);
	return (0);
}
