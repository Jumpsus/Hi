/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:50:44 by pratanac          #+#    #+#             */
/*   Updated: 2022/02/22 19:55:01 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_trim(char const *str, char c)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == c)
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	count;
	char	*trimmed;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_is_trim(set, s1[start]))
		start++;
	while ((end > start) && ft_is_trim(set, s1[end - 1]))
		end--;
	trimmed = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!trimmed)
		return (NULL);
	count = 0;
	while (start < end)
		trimmed[count++] = s1[start++];
	trimmed[count] = '\0';
	return (trimmed);
}
