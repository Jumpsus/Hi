/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:08:34 by pratanac          #+#    #+#             */
/*   Updated: 2022/02/19 23:47:55 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t			count;
	unsigned char	*tozero_str;

	count = 0;
	tozero_str = (unsigned char *)str;
	while (count < n)
	{
		tozero_str[count] = 0;
		count++;
	}
}
