/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:30:48 by pratanac          #+#    #+#             */
/*   Updated: 2022/02/23 14:18:26 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_s;
	size_t	len_d;

	len_s = 0;
	len_d = ft_strlen(dst);
	if (dstsize == 0 || dstsize < len_d)
	{
		len_s = ft_strlen(src);
		return (len_s + dstsize);
	}
	while (((len_d + len_s) < (dstsize - 1)) && src[len_s])
	{
		dst[len_d + len_s] = src[len_s];
		len_s++;
	}
	dst[len_d + len_s] = '\0';
	while (src[len_s])
	{
		len_s++;
	}
	return (len_d + len_s);
}
