/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:26:38 by ioromero          #+#    #+#             */
/*   Updated: 2021/10/25 11:18:03 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listt	*ft_lstmap(t_listt *lst, void *(*f)(void *), void (*del)(void *))
{
	t_listt	*tmp;
	t_listt	*new;
	t_listt	*bgn;

	if (lst)
	{
		tmp = lst;
		bgn = ft_lstnew(f(tmp->content));
		if (!bgn)
			return (0);
		tmp = tmp->nx;
		while (tmp)
		{
			new = ft_lstnew(f(tmp->content));
			if (!new)
			{
				ft_lstclear(&bgn, del);
				return (0);
			}
			ft_lstadd_back(&bgn, new);
			tmp = tmp->nx;
		}
		return (bgn);
	}
	return (0);
}
