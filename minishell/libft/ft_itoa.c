/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:58:27 by ioromero          #+#    #+#             */
/*   Updated: 2021/10/08 11:13:34 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_char(int n, char *s, int i)
{
	if (n / 10)
	{
		ft_char(n / 10, s, i + 1);
	}
	s[i] = '0' + n % 10;
}

static void	ft_rev_str(char	*s, int len)
{
	int	i;
	int	temp;

	i = 0;
	while (i < (len / 2))
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
		i++;
	}
}

static int	n_len(int n, int i)
{
	if (n / 10)
		return (n_len (n / 10, ++i));
	else
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		sign;

	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign = -1;
	}
	len = n_len(n, 0);
	s = (char *)malloc((len + 1 + ((sign - 1) * -1 - 1)) * sizeof(char));
	if (!s)
		return (0);
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	ft_char(n, s, 0);
	if (sign < 0)
		s[len] = '-';
	s[len - sign] = 0;
	ft_rev_str(s, len - sign);
	return (s);
}
