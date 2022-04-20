/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:10:35 by pratanac          #+#    #+#             */
/*   Updated: 2022/02/22 23:36:23 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	count;

	if (len > (ft_strlen(s) - start))
	{
		if (ft_strlen(s) >= (size_t)start)
		{
			len = ft_strlen(s) - start;
		}
	}
	if (start > ft_strlen(s))
		len = 0;
	sub = (char *)malloc(sizeof(*s) * (len + 1));
	if (!s || !sub)
		return (NULL);
	count = 0;
	while (start < ft_strlen(s) && (count < len))
	{
		sub[count++] = s[start++];
	}
	sub[count] = '\0';
	return (sub);
}
