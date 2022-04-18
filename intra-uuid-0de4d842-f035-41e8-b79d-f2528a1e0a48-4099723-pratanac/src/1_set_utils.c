/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_set_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:31:36 by pratanac          #+#    #+#             */
/*   Updated: 2022/04/18 20:32:07 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "FDF.h"

void	free_split(char	**split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_arr(t_posit **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_len_arr(t_posit **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
	{
		i++;
	}
	return (i);
}

int	ft_len_posit(t_posit *posit)
{
	int	i;

	i = 0;
	while (posit[i].flag)
	{
		i++;
	}
	return (i);
}

int	ft_len_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
