/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:08:18 by eukwon            #+#    #+#             */
/*   Updated: 2022/11/07 15:23:00 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	send_bit(int pid, char *str, int str_len)
{
	int		i;
	char	c;

	while (str_len-- > -1)
	{
		i = 0;
		c = *str++;
		while (i < 8)
		{
			if (c << i & 128)
			{
				if (kill(pid, SIGUSR2) == -1)
					return (-1);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					return (-1);
			}
			usleep(100);
			i++;
		}
	}
	return (0);
}

static void	handler_sigusr(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putstr_fd("Send message to Server: SUCCESS (", STDOUT_FILENO);
		ft_putnbr_fd(received, STDOUT_FILENO);
		ft_putstr_fd("bytes)\n", STDOUT_FILENO);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	int	check_server;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr_fd("USAGE: ./client [Server PID] [Message]\n", STDOUT_FILENO);
		exit(0);
	}
	ft_putstr_fd("[Client PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("]\n", STDOUT_FILENO);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	check_server = send_bit(ft_atoi(argv[1]), argv[2], ft_strlen(argv[2]));
	while (1)
	{
		if (check_server == -1)
		{
			ft_putstr_fd("Send message to Server: FAIL\n", STDOUT_FILENO);
			exit(0);
		}
		pause();
	}
}
