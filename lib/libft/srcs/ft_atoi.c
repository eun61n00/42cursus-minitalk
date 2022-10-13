/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:02:20 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/05 00:13:23 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "stdio.h"

static int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	ret;

	sign = 1;
	ret = 0;
	while (is_whitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + (*str++ - '0');
		if (ret > 2147483648 || (ret == 2147483648 && sign == 1))
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
	}
	return (sign * (int)ret);
}
