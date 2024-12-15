/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:42:45 by lrecine-          #+#    #+#             */
/*   Updated: 2024/11/06 18:21:01 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int			ft_printf(const char *format, ...);
void		ft_putchar(char c, int *count);
void		ft_putstr(char *args, int *count);
void		ft_hexa(unsigned int args, char c, int *count);
void		ft_hexa_p(unsigned long args, char c, int *count);
void		ft_putnbr(int args, int *count);
void		ft_putnbr_u(unsigned int args, int *count);

#endif