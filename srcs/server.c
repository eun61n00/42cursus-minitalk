/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:08:12 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/05 04:55:53 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	print_client_pid(pid_t client_pid)
{
	ft_putstr_fd("\n[Client PID: ", 1);
	ft_putnbr_fd(client_pid, 1);
	ft_putstr_fd("]\n", 1);
}

static void	put_bit(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (c == 0)
		{
			print_client_pid(client_pid);
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			system("leaks server");
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("[Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]\n", 1);
	s_sigaction.sa_sigaction = put_bit;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
