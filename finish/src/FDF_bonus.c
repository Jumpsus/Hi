/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:43:56 by pratanac          #+#    #+#             */
/*   Updated: 2022/04/20 14:14:18 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "FDF.h"

int	destroy(t_var *param)
{
	mlx_destroy_window(param->mlx, param->win);
	free_arr(param->posit);
	del_img(param);
	free(param->mlx);
	exit(0);
	return (0);
}

t_posit	**init_position(int argc, char **argv)
{
	t_adj	adj;
	t_posit	**posit;

	if (argc != 2)
	{
		ft_putstr_fd("Usage ./fdf <fdf file> \n", 2);
		exit(1);
	}
	posit = convert_fv(set_input(argv));
	adj = get_adjust(posit);
	posit = scaling_arr(posit, adj.scale);
	posit = offset_arr(posit, adj.offset_x, adj.offset_y);
	return (posit);
}

void	handle_error(t_posit **posit)
{
	ft_putstr_fd("Cannot Create Window \n", 2);
	free_arr(posit);
	exit (2);
}

int	mouse_hook(int button, int x, int y, t_var *param)
{
	if (button == 4)
	{
		param->posit = scaling_arr(param->posit, 2.0);
		param->posit = offset_arr(param->posit, -1 * x, -1 * y);
	}
	else if (button == 5)
	{
		param->posit = scaling_arr(param->posit, 0.5);
		param->posit = offset_arr(param->posit, 0.5 * x, 0.5 * y);
	}
	else if (button == 1)
	{
		if (!(y < 0 || y > WIN_H))
		{
			param->last_x = x;
			param->last_y = y;
		}
	}
	clean_img(param);
	draw_map(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img.img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	var;

	var.posit = init_position(argc, argv);
	var.z = (get_size(var.posit)).max_z;
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, WIN_W, WIN_H, "FDF");
	var.img.img_ptr = mlx_new_image(var.mlx, WIN_W, WIN_H);
	var.img.data = (int *)mlx_get_data_addr(var.img.img_ptr, &var.img.bpp,
			&var.img.size_l, &var.img.endian);
	if (!var.mlx || !var.win)
		handle_error(var.posit);
	draw_map(&var);
	mlx_put_image_to_window(var.mlx, var.win, var.img.img_ptr, 0, 0);
	mlx_key_hook(var.win, keyboard_input, &var);
	mlx_hook(var.win, 17, 0L, destroy, &var);
	mlx_expose_hook(var.win, expose_hook, &var);
	mlx_mouse_hook (var.win, mouse_hook, &var);
	mlx_loop(var.mlx);
	return (0);
}
