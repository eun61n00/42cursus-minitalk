/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:57:55 by eukwon            #+#    #+#             */
/*   Updated: 2022/07/14 11:24:07 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static unsigned int	word_cnt(char const *s, char c)
{
	size_t			i;
	size_t			start_idx;
	unsigned int	cnt;

	i = 0;
	cnt = 0;
	start_idx = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start_idx = i;
		while (s[i] && s[i] != c)
			i++;
		if (start_idx != i)
			cnt++;
	}
	return (cnt);
}

static int	free_all(char **split_arr)
{
	size_t	i;

	i = 0;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
	return (0);
}

static int	split_str(char const *s, char c, char **split_arr)
{
	size_t	i;
	size_t	j;
	size_t	start_idx;

	i = 0;
	j = 0;
	start_idx = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start_idx = i;
		while (s[i] && s[i] != c)
			i++;
		if (start_idx != i)
		{
			split_arr[j] = ft_substr(s, start_idx, i - start_idx);
			if (split_arr[j] == NULL)
				return (free_all(split_arr));
			j++;
		}
	}
	split_arr[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char			**split_arr;

	split_arr = (char **)malloc(sizeof(char *) * (word_cnt(s, c) + 1));
	if (split_arr == NULL)
		return (NULL);
	if (!split_str(s, c, split_arr))
	{
		free(split_arr);
		split_arr = NULL;
	}
	return (split_arr);
}
