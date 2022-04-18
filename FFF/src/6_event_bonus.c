
#include "libft.h"
#include "FDF.h"

int	destroy(t_var *param)
{
	mlx_destroy_window(param->mlx, param->win);
	free_arr(param->posit);
	exit(0);
	return (0);
}

void	event_rotation(t_var *param)
{
	t_adj	adj;

	param->posit = rotate_arr(param->posit);
	param->posit = convert_fv(param->posit);
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
	if (keynote == KEY_LEFT)
		param->posit = offset_arr(param->posit, (WIN_W / 10), 0);
	if (keynote == KEY_RIGHT)
		param->posit = offset_arr(param->posit, (-1 * WIN_W / 10), 0);
	if (keynote == KEY_UP)
		param->posit = offset_arr(param->posit, 0, (WIN_H / 10));
	if (keynote == KEY_DOWN)
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
/*
int     main(int argc, char ** argv)
{
	t_posit **posit;
	t_var	var;
	t_adj	adj;

	posit = set_input(argv);
	posit = convert_iso(posit);
	adj = get_adjust(posit);
	//printf("%f",adj.scale);
	fflush(stdout);
	posit = scaling_arr(posit, adj.scale);
	posit = offset_arr(posit, adj.offset_x, adj.offset_y);

var.mlx = mlx_init();
var.win = mlx_new_window(var.mlx, WIN_W, WIN_H, "FDF");
var.posit = posit;

draw_horizon(var.mlx, var.win, var.posit);
draw_vertical(var.mlx, var.win, var.posit);
mlx_key_hook(var.win, keyboard_input, &var);
mlx_mouse_hook(var.win, keyboard_input, &var);
mlx_hook(var.win, 17 , 0L, destroy, &var);
mlx_loop(var.mlx);
free_arr(posit);
return (0);
}
*/
