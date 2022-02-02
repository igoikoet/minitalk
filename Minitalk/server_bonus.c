/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoikoet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:00:19 by igoikoet          #+#    #+#             */
/*   Updated: 2022/01/25 21:26:24 by igoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	interpreter(int sign)
{
	static int		i;
	static int		bit;

	if (sign == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		if (!i)
			write(1, "\n", 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Invalid number of arguments\n", 1);
	}
	pid = getpid();
	ft_putstr_fd("This is your PID:\n", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\nWaiting for message...\n", 1);
	while (argc == 1)
	{
		signal(SIGUSR1, interpreter);
		signal(SIGUSR2, interpreter);
		pause ();
	}
	return (0);
}
