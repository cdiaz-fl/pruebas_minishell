/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:01:31 by ioromero          #+#    #+#             */
/*   Updated: 2021/10/07 10:54:48 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_str(t_info *info, char *str)
{
	if (!str)
		info->size += write(1, "(null)", 6);
	else
		while (*str)
			info->size += write(1, str++, 1);
}

void	put_nbr(t_info *info, long int n)
{
	char	c;

	if (n == -2147483648)
	{
		info->size += write (1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		info->size += write(1, "-", 1);
		n = n * -1;
	}
	if (n / 10)
		put_nbr(info, n / 10);
	c = 48 + n % 10;
	info->size += write(1, &c, 1);
}

void	hex(t_info *info, unsigned long int n, int is_lower)
{
	char	*base;

	if (is_lower)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n / 16 > 0)
	{
		hex(info, n / 16, is_lower);
		info->size += write(1, &base[n % 16], 1);
	}
	else
		info->size += write(1, &base[n], 1);
}

void	ft_formart_eval(t_info *info, char c)
{
	if (c == 'c')
	{
		c = va_arg(info->args, int);
		info->size += write(1, &c, 1);
	}
	else if (c == 's' )
		put_str(info, va_arg(info->args, char *));
	else if (c == 'd' || c == 'i')
		put_nbr(info, va_arg(info->args, int));
	else if (c == 'u')
		put_nbr(info, va_arg(info->args, unsigned int));
	else if (c == 'p')
	{
		info->size += write(1, "0x", 2);
		hex(info, va_arg(info->args, unsigned long int), 1);
	}
	else if (c == 'x')
		hex(info, va_arg(info->args, unsigned int), 1);
	else if (c == 'X')
		hex(info, va_arg(info->args, unsigned int), 0);
}

int	ft_printf(const char *str, ...)
{
	t_info	*info;
	size_t	i;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (-1);
	info->size = 0;
	i = 0;
	va_start(info->args, str);
	while (str[i])
	{
		if (str[i++] != '%')
			info->size += write(1, &str[i - 1], 1);
		else if (str[i] == '%')
			info->size += write (1, &str[i++], 1);
		else
			ft_formart_eval(info, str[i++]);
	}
	va_end(info->args);
	i = info->size;
	free (info);
	return (i);
}
