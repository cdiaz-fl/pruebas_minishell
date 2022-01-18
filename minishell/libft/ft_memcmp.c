/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:14:29 by ioromero          #+#    #+#             */
/*   Updated: 2021/05/27 09:11:07 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*aux;
	unsigned char	*aux2;

	aux = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	while (n--)
	{
		if (*aux++ != *aux2++)
			return (*(aux - 1) - *(aux2 - 1));
	}
	return (0);
}
