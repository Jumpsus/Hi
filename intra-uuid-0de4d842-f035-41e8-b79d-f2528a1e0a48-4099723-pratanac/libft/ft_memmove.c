/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:49:06 by pratanac          #+#    #+#             */
/*   Updated: 2022/02/22 17:00:30 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	count;

	s = (char *)src;
	d = (char *)dest;
	count = 0;
	if (!s && !d)
		return (NULL);
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (count < n)
		{
			d[count] = s[count];
			count++;
		}
	}
	return (dest);
}
