/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:24:22 by pratanac          #+#    #+#             */
/*   Updated: 2022/02/20 12:20:27 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		count;

	len = 0;
	count = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
	{
		return (NULL);
	}
	while (src[count] != '\0')
	{
		dup[count] = src[count];
		count++;
	}
	dup[count] = '\0';
	return (dup);
}
