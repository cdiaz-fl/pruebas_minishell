/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:19:33 by ioromero          #+#    #+#             */
/*   Updated: 2021/05/26 10:20:24 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*dst_c;
	char	*src_c;
	size_t	size_c;
	size_t	dst_length;

	dst_c = dst;
	src_c = (char *)src;
	size_c = dstsize;
	while (size_c-- > 0 && *dst_c)
		dst_c++;
	dst_length = dst_c - dst;
	size_c = dstsize - dst_length;
	if (size_c <= 0)
		return (dst_length + ft_strlen(src_c));
	while (*src_c)
	{
		if (size_c > 1)
		{
			*dst_c++ = *src_c;
			size_c--;
		}
		src_c++;
	}
	*dst_c = 0;
	return (dst_length + (src_c - src));
}
