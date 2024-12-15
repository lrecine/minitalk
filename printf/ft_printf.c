/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:17:14 by lrecine-          #+#    #+#             */
/*   Updated: 2024/11/06 18:20:22 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *args, int *count)
{
	int	i;

	i = 0;
	if (args == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (args[i])
	{
		ft_putchar(args[i], count);
		i++;
	}
}

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

static void	ft_search(char *format, va_list args, size_t i, int *count)
{
	if (format[i] == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (format[i] == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format[i] == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), count);
	else if (format[i] == 'x' || format[i] == 'X')
		ft_hexa(va_arg(args, unsigned long), format[i], count);
	else if (format[i] == 'p')
		ft_hexa_p(va_arg(args, unsigned long), format[i], count);
	else
		ft_putchar('%', count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	size_t	i;

	if (!format)
		return (-1);
	va_start (args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_search((char *)format, args, i, &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
