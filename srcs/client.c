/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:08:18 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/05 04:55:42 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	send_bit(int pid, char *str)
{
	int		i;
	char	c;
	int		str_len;

	str_len = ft_strlen(str);
	while (str_len-- > -1)
	{
		i = 0;
		c = *str++;
		while (i < 8)
		{
			if (c << i & 128)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			i++;
		}
	}
	return ;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

static void	handler_sigusr(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
	{
		++received;
	}
	else
	{
		ft_putstr_fd("Send message to Server: SUCCESS (", 1);
		ft_putnbr_fd(received, 1);
		ft_putstr_fd("bytes)\n", 1);
		system("leaks client")
;		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3 || !ft_strlen(argv[2]))
		exit(0);
	ft_putstr_fd("[Client PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]\n", 1);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	send_bit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
