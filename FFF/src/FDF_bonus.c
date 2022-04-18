
#include "libft.h"
#include "FDF.h"

int     main(int argc, char ** argv)
{
	t_posit **posit;
	t_var	var;
	t_adj	adj;

	if (argc != 2)
	{
		ft_putstr_fd("USAGE: ./FDF <Your file> \n", 2);
		return (0);
	}
	posit = convert_fv(set_input(argv));
	adj = get_adjust(posit);
	posit = scaling_arr(posit, adj.scale);
	posit = offset_arr(posit, adj.offset_x, adj.offset_y);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, WIN_W, WIN_H, "FDF");
	var.posit = posit;
	var.z = (get_size(posit)).max_z;
	draw_horizon(var.mlx, var.win, var.posit);
	draw_vertical(var.mlx, var.win, var.posit);
	mlx_key_hook(var.win, keyboard_input, &var);
	mlx_hook(var.win, 17 , 0L, destroy, &var);
	mlx_expose_hook(var.win, expose_hook, &var);
	mlx_loop(var.mlx);
	free_arr(posit);
	return (0);
}
