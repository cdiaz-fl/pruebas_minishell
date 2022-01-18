/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:13:31 by ioromero          #+#    #+#             */
/*   Updated: 2021/06/02 12:35:55 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*newptr;
	size_t	cursize;

	if (ptr == 0)
		return (malloc(size));
	cursize = sizeof(ptr);
	if (size <= cursize)
		return (ptr);
	newptr = malloc(size);
	ft_memcpy(ptr, newptr, cursize);
	free(ptr);
	return (newptr);
}
