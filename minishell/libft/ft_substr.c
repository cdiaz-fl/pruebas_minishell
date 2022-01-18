/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 09:34:14 by ioromero          #+#    #+#             */
/*   Updated: 2021/06/04 10:55:49 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	length;
	size_t	i;

	if (!s)
		return (0);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	length = ft_strlen(s);
	i = 0;
	while (i < len && i + start < length)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
