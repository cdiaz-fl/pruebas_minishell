/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:51:26 by ioromero          #+#    #+#             */
/*   Updated: 2021/10/25 11:18:03 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_listt **lst, void (*del)(void *))
{
	t_listt	*tmp;

	while (lst && *lst)
	{
		tmp = (*lst)->nx;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
