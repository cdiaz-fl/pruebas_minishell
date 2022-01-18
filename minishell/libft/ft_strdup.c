/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:39:41 by ioromero          #+#    #+#             */
/*   Updated: 2021/06/22 13:05:29 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*aux;

	aux = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!aux)
		return (0);
	ft_strcpy(aux, s1);
	return (aux);
}
