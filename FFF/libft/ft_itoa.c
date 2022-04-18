/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:50:36 by pratanac          #+#    #+#             */
/*   Updated: 2022/02/22 18:22:10 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_mem(long int num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		num = -1 * num;
		count++;
	}
	while (num > 9)
	{
		num = num / 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	long int	num;
	char		*str;
	int			len;

	num = (long int)n;
	len = ft_count_mem(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		num = -1 * num;
		str[0] = '-';
	}
	str[len] = 0;
	while (num > 9)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	str[--len] = num + '0';
	return (str);
}
