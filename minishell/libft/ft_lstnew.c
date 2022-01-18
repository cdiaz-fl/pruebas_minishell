/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:08:45 by ioromero          #+#    #+#             */
/*   Updated: 2021/10/25 11:18:03 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listt	*ft_lstnew(void *content)
{
	t_listt	*new;

	new = (t_listt *)malloc(sizeof(*new));
	if (!new)
		return (0);
	new->content = content;
	new->nx = 0;
	return (new);
}
