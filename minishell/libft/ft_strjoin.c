/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:40:36 by ioromero          #+#    #+#             */
/*   Updated: 2021/11/18 11:46:01 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		len1;
	int		len2;
	int		i;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = (char *)malloc((len1 + len2 + 1) * sizeof(*s1));
	i = 0;
	if (!ptr)
		return (0);
	while (i < len1)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		ptr[i] = s2[i - len1];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
