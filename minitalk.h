/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:23:40 by hassimi           #+#    #+#             */
/*   Updated: 2022/12/24 11:14:08 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_atoi(const char *s);
void	ft_putnbr(int i);
void	ft_putchar(int i);
int		ft_print(int *a);
void	do_thing(int *i, int *bit, int *f, int a);

#endif
