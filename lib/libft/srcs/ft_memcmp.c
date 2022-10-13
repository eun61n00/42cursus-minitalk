/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:29:30 by eukwon            #+#    #+#             */
/*   Updated: 2022/07/14 11:24:07 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;

	s1_ptr = (const unsigned char *)s1;
	s2_ptr = (const unsigned char *)s2;
	while (n--)
	{
		if ((int)*s1_ptr != (int)*s2_ptr)
			return ((int)*s1_ptr - (int)*s2_ptr);
		s1_ptr++;
		s2_ptr++;
	}
	return (0);
}
