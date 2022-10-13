/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:06:18 by eukwon            #+#    #+#             */
/*   Updated: 2022/07/14 11:24:07 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*joinstr;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joinstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (joinstr == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		joinstr[i] = *s1++;
		i++;
	}
	while (i < s1_len + s2_len)
	{
		joinstr[i] = *s2++;
		i++;
	}
	joinstr[i] = '\0';
	return (joinstr);
}
