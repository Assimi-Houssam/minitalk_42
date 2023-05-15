/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:26:18 by hassimi           #+#    #+#             */
/*   Updated: 2022/12/20 16:00:18 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_things(char things, int pid)
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
		usleep(100);
	}
}

int	main(int argc, char const **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(2, "\e[0;31m you need 3 argument\n", 29);
		write(2, "\e[0;31m the pid , and the string to send", 41);
	}
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_things(argv[2][i], pid);
			i++;
		}
		send_things('\0', pid);
	}
	return (0);
}
