/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:56:55 by lrecine-          #+#    #+#             */
/*   Updated: 2025/01/20 19:23:03 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_wait_response = 0;

void	handle_response(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("\033[0;32mmessage recieved ✓\033[0m\n");
	g_wait_response = 1;
}

void	send_bits(int pid, char *str)
{
	static int	bit;

	while (*str)
	{
		bit = 8;
		while (bit--)
		{
			g_wait_response = 0;
			if ((*str >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (!g_wait_response)
				;
		}
		str++;
	}
	bit = 8;
	while (bit--)
	{
		g_wait_response = 0;
		kill(pid, SIGUSR1);
		while (!g_wait_response)
			;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, handle_response);
	signal(SIGUSR2, handle_response);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_bits(pid, av[2]);
	}
	else
	{
		ft_printf("\033[0;31mError ❌\033[0m\n");
		return (1);
	}
	return (0);
}
