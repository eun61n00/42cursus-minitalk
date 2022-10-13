/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:02:03 by eukwon            #+#    #+#             */
/*   Updated: 2022/07/14 11:24:07 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	ret;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	ret = 0;
	while (dst[ret] && ret < dstsize)
		ret++;
	if (ret == dstsize)
		return (srclen + ret);
	while ((dstlen + 1 < dstsize) && src[i])
		dst[dstlen++] = src[i++];
	dst[dstlen] = '\0';
	return (srclen + ret);
}
