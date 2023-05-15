/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:27:36 by hassimi           #+#    #+#             */
/*   Updated: 2022/12/20 13:48:07 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_space(const char a)
{
	if (a == ' ' || a == '\t' || a == '\n' || a == '\v'
		|| a == '\r' || a == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	n;
	int	c;

	i = 0;
	n = 0;
	c = 1;
	while (check_space(s[i]))
		i++;
	if (s[i] == 45)
	{
		c = -1;
		i++;
	}
	else if (s[i] == 43)
		i++;
	while (s[i] >= 48 && s[i] <= 57)
	{
		n = n * 10 + (s[i] - 48);
		i++;
	}
	return (c * n);
}
