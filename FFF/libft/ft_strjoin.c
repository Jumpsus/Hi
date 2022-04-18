/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:47:42 by pratanac          #+#    #+#             */
/*   Updated: 2022/02/22 21:31:53 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	count;
	size_t	len;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	len = 0;
	if (!join || (!s1 || !s2))
		return (NULL);
	count = 0;
	while (s1[count])
	{
		join[len++] = s1[count++];
	}
	count = 0;
	while (s2[count])
	{
		join[len++] = s2[count++];
	}
	join[len] = '\0';
	return (join);
}
