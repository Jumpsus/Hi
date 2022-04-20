/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_drawing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:40:01 by pratanac          #+#    #+#             */
/*   Updated: 2022/04/18 20:40:42 by pratanac         ###   ########.fr       */
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

int	drawing(void *mlx, void *win, t_draw t)
{
	int		pixels;
	double	del_x;
	double	del_y;
	double	del_color;

	pixels = sqrt((t.e_x - t.s_x) * (t.e_x - t.s_x) + (
				t.e_y - t.s_y) * (t.e_y - t.s_y));
	if (pixels == 0)
	{
		return (0);
	}
	del_x = (t.e_x - t.s_x) / pixels;
	del_y = (t.e_y - t.s_y) / pixels;
	del_color = (t.e_c - t.s_c) / pixels;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, t.s_x, t.s_y, t.s_c);
		t.s_x = t.s_x + del_x;
		t.s_y = t.s_y + del_y;
		t.s_c = t.s_c + del_color;
		pixels--;
	}
	return (1);
}

int	draw_horizon(void *mlx, void *win, t_posit **posit)
{
	int		i;
	int		j;
	t_draw	draw_me;

	i = 0;
	while (posit[i])
	{
		j = 0;
		while (j < (ft_len_posit(posit[i]) - 1))
		{
			draw_me = fill_target(posit[i][j], posit[i][j + 1]);
			drawing(mlx, win, draw_me);
			j++;
		}
		i++;
	}
	return (0);
}

int	draw_vertical(void *mlx, void *win, t_posit **posit)
{
	int		i;
	int		j;
	t_draw	draw_me;

	j = 0;
	while (posit[0][j].flag)
	{
		i = 0;
		while (posit[i])
		{
			if (posit[i + 1])
			{
				draw_me = fill_target(posit[i][j], posit[i + 1][j]);
				drawing(mlx, win, draw_me);
			}
			i++;
		}
		j++;
	}
	return (0);
}
/*
int     main(int argc, char ** argv)
{
	argc = 0;
	t_posit **posit;
	t_adj adj;
	t_draw	t;
	(void) argc;

	int     i;
	int     j;

	i = 0;
	j = 0;
	posit = set_input(argv);
//	printf("%d\n",arg[9][3].z);
	posit = convert_iso(posit);
//	posit = rotate_arr(posit);
//	posit = rotate_arr(posit);
	posit = convert_iso(posit);
	adj = get_adjust(posit);
	posit = scaling_arr(posit, adj.scale);
	posit = offset_arr(posit, adj.offset_x, adj.offset_y);
	void *mlx = mlx_init();	
	void *win = mlx_new_window(mlx, WIN_W, WIN_H, "Tutorial Window - Draw Line");
	
	draw_horizon(mlx, win, posit);
	draw_vertical(mlx, win, posit);
	mlx_loop(mlx);
	free_arr(posit);
	return (0);
}
*/
