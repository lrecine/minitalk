/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:52:46 by lrecine-          #+#    #+#             */
/*   Updated: 2024/11/06 18:22:09 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned int args, char c, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (args >= 16)
		ft_hexa(args / 16, c, count);
	ft_putchar(base[args % 16], count);
}

void	ft_hexa_p(unsigned long args, char c, int *count)
{
	static char	base[] = "0123456789abcdef";

	if (args == 0)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	if (c == 'p')
	{
		ft_putchar('0', count);
		ft_putchar('x', count);
		c = 'x';
	}
	if (args >= 16)
		ft_hexa_p(args / 16, c, count);
	ft_putchar(base[args % 16], count);
}

void	ft_putnbr(int args, int *count)
{
	if (args == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (args < 0)
	{
		ft_putchar('-', count);
		args = args * (-1);
	}
	if (args >= 10)
		ft_putnbr(args / 10, count);
	ft_putchar((args % 10) + '0', count);
}

void	ft_putnbr_u(unsigned int args, int *count)
{
	if (args >= 10)
		ft_putnbr_u(args / 10, count);
	ft_putchar((args % 10) + '0', count);
}
