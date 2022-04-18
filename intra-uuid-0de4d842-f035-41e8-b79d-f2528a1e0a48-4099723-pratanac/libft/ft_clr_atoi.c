/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:45:51 by pratanac          #+#    #+#             */
/*   Updated: 2022/04/18 20:26:44 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_clr_atoi(const char *str)
{
	long int	result;
	int			i;

	result = 0;
	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	if (str[i] != ',')
		return (16777215);
	i++;
	while (str[i] == '0')
		i++;
	if (str[i] == 'x')
		i++;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || (
				ft_tolower(str[i]) >= 'a' && ft_tolower(str[i]) <= 'f')))
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = 16 * result + (str[i] - '0');
		else
			result = 16 * result + (ft_tolower(str[i]) - 'a' + 10);
		i++;
	}
	return ((int)(result));
}
