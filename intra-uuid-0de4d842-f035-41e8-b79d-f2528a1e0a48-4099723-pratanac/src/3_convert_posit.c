/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_convert_posit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:34:12 by pratanac          #+#    #+#             */
/*   Updated: 2022/04/18 20:38:14 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"
#include "libft.h"

t_posit	**convert_fv(t_posit **posit)
{
	int	i;
	int	j;

	i = 0;
	while (posit[i])
	{
		j = 0;
		while (posit[i][j].flag)
		{
			posit[i][j].x_iso = (posit[i][j].x);
			posit[i][j].y_iso = (posit[i][j].y);
			j++;
		}
		i++;
	}
	return (posit);
}

t_posit	**convert_iso(t_posit **posit)
{
	int	i;
	int	j;

	i = 0;
	while (posit[i])
	{
		j = 0;
		while (posit[i][j].flag)
		{
			posit[i][j].x_iso = (posit[i][j].x / sqrt(2)) - (
					posit[i][j].z / sqrt(2));
			posit[i][j].y_iso = (posit[i][j].x / sqrt(6)) + (
					posit[i][j].y * sqrt(2) / sqrt(3)) + (
					posit[i][j].z / sqrt(6));
			j++;
		}
		i++;
	}
	return (posit);
}

t_posit	**rotate_arr(t_posit **posit)
{
	int	i;
	int	j;
	int	temp_x;

	i = 0;
	while (posit[i])
	{
		j = 0;
		while (posit[i][j].flag)
		{
			temp_x = posit[i][j].x;
			posit[i][j].x = posit[i][j].z;
			posit[i][j].z = -1 * temp_x;
			j++;
		}
		i++;
	}
	return (posit);
}

t_posit	**scaling_arr(t_posit **posit, double scale)
{
	int	i;
	int	j;

	i = 0;
	while (posit[i])
	{
		j = 0;
		while (posit[i][j].flag)
		{
			posit[i][j].x_iso *= scale;
			posit[i][j].y_iso *= scale;
			j++;
		}
		i++;
	}
	return (posit);
}

/* use offset after scaling */
t_posit	**offset_arr(t_posit **posit, double offset_x, double offset_y)
{
	int	i;
	int	j;

	i = 0;
	while (posit[i])
	{
		j = 0;
		while (posit[i][j].flag)
		{
			posit[i][j].x_iso += offset_x;
			posit[i][j].y_iso += offset_y;
			j++;
		}
		i++;
	}
	return (posit);
}
