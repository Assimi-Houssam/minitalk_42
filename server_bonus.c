/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:21:25 by hassimi           #+#    #+#             */
/*   Updated: 2022/12/24 11:09:57 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	do_thing(int *i, int *bit, int *f, int a)
{
	if (a == 1)
		*f = 0;
	*i = 0;
	*bit = 0;
}

int	baff(int *i, int *f, int n)
{
	static int	a[4];

	a[*f] = *i;
	*f = *f +1;
	if (n == 1 && *f == 4)
	{
		write(1, &a[0], 1);
		write(1, &a[1], 1);
		write(1, &a[2], 1);
		write(1, &a[3], 1);
		return (0);
	}
	else if (n == 2 && *f == 3)
	{
		write(1, &a[0], 1);
		write(1, &a[1], 1);
		write(1, &a[2], 1);
		return (0);
	}
	return (*f);
}

int	unicode(int i)
{
	static int	n;

	if (i == 240)
		n = 1;
	if (i == 226)
		n = 2;
	return (n);
}

static void	handle_things(int signal, siginfo_t *info)
{
	static int	bit;
	static int	i;
	static int	pid;
	static int	n;
	static int	f;

	if (pid != info->si_pid)
		do_thing(&i, &bit, &f, 1);
	pid = info->si_pid;
	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (i >= 0 && i <= 127)
			write(1, &i, 1);
		else
		{
			n = unicode(i);
			f = baff(&i, &f, n);
		}
		do_thing(&i, &bit, &f, 0);
	}
	usleep(200);
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char const *argv[])
{
	int					pid;
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
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
		while (1)
			pause();
	}
	return (0);
}
