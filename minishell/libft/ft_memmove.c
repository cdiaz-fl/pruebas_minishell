/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:17:32 by ioromero          #+#    #+#             */
/*   Updated: 2021/05/27 09:12:13 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*aux;
	unsigned char	*aux2;

	aux = dst;
	aux2 = (unsigned char *)src;
	if (aux > aux2)
	{
		while (len--)
			aux[len] = aux2[len];
	}
	else if (aux < aux2)
		ft_memcpy(dst, src, len);
	return (dst);
}
