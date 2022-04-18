/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_event.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:40:56 by pratanac          #+#    #+#             */
/*   Updated: 2022/04/18 20:50:44 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "FDF.h"

void	event_rotation(t_var *param)
{
	t_adj	adj;

	param->posit = rotate_arr(param->posit);
	param->posit = convert_iso(param->posit);
	adj = get_adjust(param->posit);
	param->posit = scaling_arr(param->posit, adj.scale);
	param->posit = offset_arr(param->posit, adj.offset_x, adj.offset_y);
	mlx_clear_window(param->mlx, param->win);
	draw_horizon_bonus(param->mlx, param->win, param->posit, param->z);
	draw_vertical_bonus(param->mlx, param->win, param->posit, param->z);
	return ;
}

void	event_zoom(int keynote, t_var *param)
{
	if (keynote == 'z')
		param->posit = scaling_arr(param->posit, 2.0);
	else if (keynote == 'x')
		param->posit = scaling_arr(param->posit, 0.5);
	mlx_clear_window(param->mlx, param->win);
	draw_horizon_bonus(param->mlx, param->win, param->posit, param->z);
	draw_vertical_bonus(param->mlx, param->win, param->posit, param->z);
	return ;
}

void	event_move(int keynote, t_var *param)
{
	if (keynote == 65361)
		param->posit = offset_arr(param->posit, (WIN_W / 10), 0);
	if (keynote == 65363)
		param->posit = offset_arr(param->posit, (-1 * WIN_W / 10), 0);
	if (keynote == 65362)
		param->posit = offset_arr(param->posit, 0, (WIN_H / 10));
	if (keynote == 65364)
		param->posit = offset_arr(param->posit, 0, (-1 * WIN_H / 10));
	mlx_clear_window(param->mlx, param->win);
	draw_horizon_bonus(param->mlx, param->win, param->posit, param->z);
	draw_vertical_bonus(param->mlx, param->win, param->posit, param->z);
	return ;
}

void	event_cut(int keynote, t_var *param)
{
	if (keynote == 'c')
	{
		if (!param->z)
			param->z = 1;
		else if (param->z < 0)
			param->z = (param->z / 2);
		else
			param->z = (param->z * 2);
	}
	else if (keynote == 'v')
	{
		if (!param->z)
			param->z = -1;
		else if (param->z < 0)
			param->z = (param->z * 2);
		else
			param->z = (param->z / 2);
	}
	mlx_clear_window(param->mlx, param->win);
	draw_horizon_bonus(param->mlx, param->win, param->posit, param->z);
	draw_vertical_bonus(param->mlx, param->win, param->posit, param->z);
}

int	keyboard_input(int keynote, t_var *param)
{
	if (keynote == 'r')
		event_rotation(param);
	if (keynote == 'x' || keynote == 'z')
		event_zoom(keynote, param);
	if (keynote >= KEY_LEFT && keynote <= KEY_DOWN)
		event_move(keynote, param);
	if (keynote == 'c' || keynote == 'v')
		event_cut(keynote, param);
	if (keynote == KEY_ESC)
	{
		mlx_destroy_window(param->mlx, param->win);
		free_arr(param->posit);
		exit(0);
	}
	return (0);
}
