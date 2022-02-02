/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoikoet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:06:38 by igoikoet          #+#    #+#             */
/*   Updated: 2022/01/25 21:15:22 by igoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

static int	send_ascii(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid_serv;
	size_t	i;

	i = 0;
	if (argc == 3)
	{
		pid_serv = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_ascii(pid_serv, argv[2][i]);
			i++;
		}
		send_ascii(pid_serv, '\n');
	}
	else
	{
		write(1, "Use: ./client [PID] string\n", 28);
		return (1);
	}
	return (0);
}
