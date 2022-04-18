#include "FDF.h"
#include "libft.h"

int	draw_horizon_bonus(void *mlx, void *win, t_posit **posit, int max_z)
{
	int	i;
	int	j;
	t_draw	draw_me;

	i = 0;
	while (posit[i])
	{
		j = 0;
		while (j < (ft_len_posit(posit[i]) - 1))
		{
			if (posit[i][j].y >= max_z && posit[i][j + 1].y >= max_z)
			{
				draw_me = fill_target(posit[i][j], posit[i][j + 1]);
				drawing(mlx, win, draw_me);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	draw_vertical_bonus(void *mlx, void *win, t_posit **posit, int max_z)
{
	int	i;
	int	j;
	t_draw	draw_me;

	j = 0;
	while (posit[0][j].flag)
	{
		i = 0;
		while (posit[i])
		{
			if (posit[i + 1])
			{
				if (posit[i][j].y >= max_z && posit[i + 1][j].y >= max_z)
				{
					draw_me = fill_target(posit[i][j], posit[i + 1][j]);
					drawing(mlx, win, draw_me);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	expose_hook(t_var *param)
{
	draw_horizon(param->mlx, param->win, param->posit);
	draw_vertical(param->mlx, param->win, param->posit);
	return (0);
}
