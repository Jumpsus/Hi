/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:13:06 by pratanac          #+#    #+#             */
/*   Updated: 2022/02/22 18:34:57 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;

	len = 0;
	str = (char *)s;
	while (str[len])
		len++;
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return (&str[len]);
		len--;
	}
	return (NULL);
}
