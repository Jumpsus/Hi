/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:20:12 by pratanac          #+#    #+#             */
/*   Updated: 2022/02/23 20:49:57 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(char const *s, char c)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	if ((s[index] != c) && s[index])
		count++;
	while (s[index])
	{
		if (s[index] == c && (s[index + 1] != c && s[index + 1]))
			count++;
		index++;
	}
	return (count);
}

char	*ft_dup(char const *s, int start, int stop)
{
	char	*dup;
	int		count;

	count = 0;
	dup = (char *)malloc(sizeof(char) * (stop - start + 1));
	if (!dup)
		return (NULL);
	while (start < stop)
	{
		dup[count] = s[start];
		count++;
		start++;
	}
	dup[count] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	index;
	int		start;
	int		count;

	start = -1;
	index = 0;
	count = 0;
	split = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!split)
		return (NULL);
	while (index <= ft_strlen(s))
	{
		if (start < 0 && s[index] != c)
			start = index;
		else if (start >= 0 && (s[index] == c || !s[index]))
		{
			split[count++] = ft_dup(s, start, index);
			start = -1;
		}
		index++;
	}
	split[count] = 0;
	return (split);
}
