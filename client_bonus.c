/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:45:11 by hassimi           #+#    #+#             */
/*   Updated: 2022/12/24 11:21:28 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_otherthings(int signal)
{
	usleep(50);
}

static void	send_things(char things, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((things & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		pause();
	}
}

void	ft_error(void)
{
	write(2, "\e[0;31m you need 3 argument\n", 29);
	write(2, "\e[0;31m the pid , and the string to send", 41);
}

int	main(int argc, char const **argv)
{
	int					pid;
	int					i;
	struct sigaction	ok;

	i = 0;
	if (argc != 3)
		ft_error();
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR1, handle_otherthings);
		while (1)
		{
			if (argv[2][i] != '\0')
				send_things(argv[2][i++], pid);
			if (argv[2][i] == '\0')
			{
				send_things('\0', pid);
				break ;
			}
		}
		write(1, "\e[1;32m\nsuccess\n", 17);
	}
	return (0);
}
