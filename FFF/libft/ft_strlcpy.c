/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:57:42 by pratanac          #+#    #+#             */
/*   Updated: 2022/02/19 23:20:26 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize == 0)
	{
		while (src[len])
			len++;
		return (len);
	}
	while ((len < (dstsize - 1)) && src[len])
	{
		dst[len] = src[len];
		len++;
	}
	if (len < dstsize)
		dst[len] = '\0';
	while (src[len])
	{
		len++;
	}
	return (len);
}
