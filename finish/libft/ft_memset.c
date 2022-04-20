/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:05:59 by pratanac          #+#    #+#             */
/*   Updated: 2022/02/19 23:50:20 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*set;
	size_t	count;

	set = (char *)b;
	count = 0;
	while (count < len)
	{
		set[count] = (char)c;
		count++;
	}
	return (b);
}
