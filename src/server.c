/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:57:49 by lrecine-          #+#    #+#             */
/*   Updated: 2025/01/20 19:23:00 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	char_completed(char **str, char *c, int *bit_c, siginfo_t *info)
{
	char	*temp;

	if (*c == 0)
	{
		ft_printf("%s\n", *str);
		free(*str);
		*bit_c = 0;
		*str = NULL;
		kill(info->si_pid, SIGUSR2);
		return (0);
	}
	temp = ft_strjoin(*str, c);
	free(*str);
	*str = temp;
	*c = 0;
	*bit_c = 0;
	return (1);
}

void	print_signal(int signal, siginfo_t *info, void *context)
{
	static char		c = 0;
	static char		*str = NULL;
	static int		bit_count = 0;

	context = NULL;
	c <<= 1;
	if (signal == SIGUSR2)
		c |= 1;
	if (!str)
		str = ft_strdup("");
	bit_count++;
	if (bit_count == 8)
	{
		if (!char_completed(&str, &c, &bit_count, info))
			return ;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("pid : ");
	ft_printf("%d\n", getpid());
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = print_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
