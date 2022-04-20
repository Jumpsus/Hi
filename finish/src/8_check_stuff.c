/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_check_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:57:32 by pratanac          #+#    #+#             */
/*   Updated: 2022/04/20 14:13:36 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"
#include "libft.h"

int	check_altitute(char *input)
{
	int	i;

	i = 0;
	if (input[i] == '-')
		i++;
	while (input[i] && input[i] != ',')
	{
		if (input[i] < '0' || input[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_color(char *input)
{
	int	i;
	int	color;

	i = 0;
	color = 6;
	if (input[i] == '0')
		i++;
	if (ft_tolower(input[i]) == 'x')
		i++;
	if (input[i] && color)
	{
		if (input[i] < '0' || input[i] > '9')
		{
			if (ft_tolower(input[i]) < 'a' || ft_tolower(input[i]) > 'f')
				return (1);
		}
		i++;
		color--;
	}
	return (input[i]);
}

int	check_input(char *input)
{
	int	i;

	i = 0;
	if (!check_altitute(input))
		return (1);
	while (input[i] && input[i] != ',')
		i++;
	if (input[i] && input[i] == ',')
	{
		return (check_color(&input[i++]));
	}
	return (0);
}
