/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:54:04 by ioromero          #+#    #+#             */
/*   Updated: 2021/06/01 11:29:58 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*aux;
	unsigned char	*aux2;

	if (!dst && !src)
		return (0);
	aux = dst;
	aux2 = (unsigned char *)src;
	while (n--)
		*aux++ = *aux2++;
	return (dst);
}
