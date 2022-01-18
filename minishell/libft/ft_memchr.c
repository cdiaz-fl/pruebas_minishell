/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 08:51:11 by ioromero          #+#    #+#             */
/*   Updated: 2021/06/01 11:59:03 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*aux;
	unsigned char	aux_c;

	aux = (unsigned char *)s;
	aux_c = c;
	while (n--)
	{
		if (*aux == aux_c)
			return (aux);
		aux++;
	}
	return (0);
}
