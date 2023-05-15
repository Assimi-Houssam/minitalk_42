/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:28:07 by hassimi           #+#    #+#             */
/*   Updated: 2022/12/23 11:36:58 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_things(int signal, siginfo_t *info)
{
	static int	bit;
	static int	i;
	static int	pid;

	if (pid != info->si_pid)
	{
		i = 0;
		bit = 0;
		pid = info->si_pid;
	}
	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		i = 0;
		bit = 0;
	}
}

int	main(int argc, char const *argv[])
{
	int					pid;
	int					i;
	struct sigaction	sa;

	sa.__sigaction_u.__sa_handler = (void *)handle_things;
	sa.sa_flags = SA_SIGINFO;
	if (argc != 1)
	{
		write(2, "\e[1;31m error: too much argument ", 34);
		return (0);
	}
	if (argc == 1)
	{
		pid = getpid();
		ft_putnbr(pid);
		ft_putchar('\n');
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	return (0);
}
