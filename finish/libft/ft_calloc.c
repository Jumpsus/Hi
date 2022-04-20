/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 00:12:02 by pratanac          #+#    #+#             */
/*   Updated: 2022/02/20 12:19:53 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*pointer;
	size_t	count;

	pointer = malloc(num * size);
	count = 0;
	if (!pointer)
		return (NULL);
	while (count < (num * size))
	{
		pointer[count] = '\0';
		count++;
	}
	return ((void *)pointer);
}
