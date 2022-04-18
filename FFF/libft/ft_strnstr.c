/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:37:54 by pratanac          #+#    #+#             */
/*   Updated: 2022/02/19 16:43:06 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (!(*needle))
		return ((char *)(haystack));
	while (haystack[x] && (x < len))
	{
		y = 0;
		while ((haystack[x + y] == needle[y]) && ((x + y) < len))
		{
			y++;
			if (!needle[y])
				return ((char *)(haystack + x));
		}
		x++;
	}
	return (NULL);
}
