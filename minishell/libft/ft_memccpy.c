/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:51:50 by ioromero          #+#    #+#             */
/*   Updated: 2021/06/01 11:55:47 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*aux;
	unsigned char	*aux2;
	unsigned char	aux_c;

	aux = dst;
	aux2 = (unsigned char *)src;
	aux_c = c;
	while (n--)
	{
		*aux++ = *aux2;
		if (*aux2++ == aux_c)
			return (aux);
	}
	return (0);
}
