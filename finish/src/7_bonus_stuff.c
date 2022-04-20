/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_bonus_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:42:47 by pratanac          #+#    #+#             */
/*   Updated: 2022/04/20 14:13:26 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"
#include "libft.h"

int	draw_map_bonus(t_var *var, int max_z)
{
	int		i;
	int		j;
	t_draw	draw_me;

	i = -1;
	while (var->posit[++i])
	{
		j = -1;
		while (var->posit[i][++j].flag)
		{
			if ((j < ft_len_posit(var->posit[i]) - 1) && var->posit[
					i][j].y >= max_z && var->posit[i][j + 1].y >= max_z)
			{
				draw_me = fill_target(var->posit[i][j], var->posit[i][j + 1]);
				drawing(var, draw_me);
			}
			if (var->posit[i + 1] && var->posit[i][
				j].y >= max_z && var->posit[i + 1][j].y >= max_z)
			{
				draw_me = fill_target(var->posit[i][j], var->posit[i + 1][j]);
				drawing(var, draw_me);
			}
		}
	}
	return (0);
}

int	expose_hook(t_var *param)
{
	draw_map(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img.img_ptr, 0, 0);
	return (0);
}
