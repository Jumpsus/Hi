
#include "libft.h"
#include "FDF.h"

t_posit	**init_position(char **argv)
{
	t_adj	adj;
	t_posit	**posit;

	posit = convert_iso(set_input(argv));
	adj = get_adjust(posit);
	posit = scaling_arr(posit, adj.scale);
	posit = offset_arr(posit, adj.offset_x, adj.offset_y);
	return (posit);
}

int	check_read(char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{	
		ft_putstr_fd("File Can't Be Opened !! \n", 2);
		exit (1);
	}
	if (read(fd, 0, 0) < 0)
	{
		ft_putstr_fd("Cannot Read the file !! \n", 2);
		exit(2);
	}
	close(fd);
	return (0);
}

int     main(int argc, char **argv)
{
	t_posit **posit;
	t_var	var;

	if (argc != 2)
	{
		ft_putstr_fd("USAGE: ./FDF <Your file> \n", 2);
		return (1);
	}
	posit = init_position(argv);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, WIN_W, WIN_H, "FDF");
	if (!var.mlx || !var.win)
	{
		ft_putstr_fd("Cannot Create Window \n", 2);
		free_arr(posit);
		return (2);
	}
	var.posit = posit;
	var.z = (get_size(posit)).max_z;	
	draw_horizon(var.mlx, var.win, var.posit);
	draw_vertical(var.mlx, var.win, var.posit);
	mlx_key_hook(var.win, keyboard_input, &var);
	mlx_hook(var.win, 17 , 0L, destroy, &var);
	mlx_expose_hook(var.win, expose_hook, &var);
	mlx_loop(var.mlx);
	return (0);
}
