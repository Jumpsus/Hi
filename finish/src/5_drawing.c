/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_drawing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:40:01 by pratanac          #+#    #+#             */
/*   Updated: 2022/04/20 14:13:03 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"
#include "libft.h"

t_draw	fill_target(t_posit start, t_posit end)
{
	t_draw	target;

	target.s_x = start.x_iso;
	target.s_y = start.y_iso;
	target.e_x = end.x_iso;
	target.e_y = end.y_iso;
	target.s_c = start.color;
	target.e_c = end.color;
	return (target);
}

int	drawing(t_var *var, t_draw t)
{
	int		pixels;
	double	del_x;
	double	del_y;
	double	del_color;

	pixels = sqrt((t.e_x - t.s_x) * (t.e_x - t.s_x) + (
				t.e_y - t.s_y) * (t.e_y - t.s_y));
	if (pixels == 0)
		return (0);
	del_x = (t.e_x - t.s_x) / pixels;
	del_y = (t.e_y - t.s_y) / pixels;
	del_color = (t.e_c - t.s_c) / pixels;
	while (pixels)
	{
		if ((t.s_x >= 0 && t.s_x <= WIN_W) && (t.s_y >= 0 && t.s_y <= WIN_H))
			var->img.data[(int)(t.s_y * WIN_W) + (int)(t.s_x)] = t.s_c;
		t.s_x = t.s_x + del_x;
		t.s_y = t.s_y + del_y;
		t.s_c = t.s_c + del_color;
		pixels--;
	}
	return (0);
}

int	draw_map(t_var *var)
{
	int		i;
	int		j;
	t_draw	draw_me;

	i = 0;
	while (var->posit[i])
	{
		j = 0;
		while (var->posit[i][j].flag)
		{
			if (j < ft_len_posit(var->posit[i]) - 1)
			{
				draw_me = fill_target(var->posit[i][j], var->posit[i][j + 1]);
				drawing(var, draw_me);
			}
			if (var->posit[i + 1])
			{
				draw_me = fill_target(var->posit[i][j], var->posit[i + 1][j]);
				drawing(var, draw_me);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	clean_img(t_var *var)
{
	int	i;

	i = 0;
	while (i < WIN_W * WIN_H)
	{
		var->img.data[i] = 0;
		i++;
	}
}

void	del_img(t_var *var)
{
	if (var->img.img_ptr)
	{
		if (var->img.img_ptr)
		{
			mlx_destroy_image(var->mlx, var->img.img_ptr);
		}
	}
}
