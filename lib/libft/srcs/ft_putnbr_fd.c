/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:11:45 by eukwon            #+#    #+#             */
/*   Updated: 2022/07/14 11:24:07 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <unistd.h>

void	write_nbr(int n, int fd)
{
	char	mod;
	char	nb_char;

	if (n / 10)
	{
		ft_putnbr_fd(n / 10, fd);
		mod = n % 10 + '0';
		write(fd, &mod, 1);
	}
	else
	{
		nb_char = n + '0';
		write(fd, &nb_char, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		write_nbr(-n, fd);
	}
	else
		write_nbr(n, fd);
}
