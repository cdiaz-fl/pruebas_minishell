/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:49:48 by ioromero          #+#    #+#             */
/*   Updated: 2021/10/25 11:18:03 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_listt **lst, t_listt *new)
{
	t_listt	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->nx = new;
		return ;
	}
	*lst = new;
}
