#include "FDF.h"
#include "libft.h"

t_posit **convert_fv(t_posit **posit)
{
	int i;
	int j;

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

/* convert_scale is from wikipedia rotate x-axis = 45 degree and then y axis = approx. 30 degree*/
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
			
			posit[i][j].x_iso = (posit[i][j].x / sqrt(2)) - (posit[i][j].z / sqrt(2));
			posit[i][j].y_iso = (posit[i][j].x / sqrt(6)) + 
				(posit[i][j].y * sqrt(2) / sqrt(3)) + (posit[i][j].z / sqrt(6));
			j++;
		}
		i++;
	}
	return (posit);
}

/* rotate before convert_iso */
t_posit **rotate_arr(t_posit **posit)
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

/*
# include <stdio.h>
int     main(int argc, char ** argv)
{
	argc = 0;
	t_posit **posit;
	(void) argc;

	int     i;
	int     j;

	i = 0;
	j = 0;
	posit = set_input(argv);
//	printf("%d\n",arg[9][3].z);
	posit = convert_iso(posit);

	void *mlx = mlx_init();	
	void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Draw Line");
	
	while (posit[i])
	{
		j = 0;
		while (posit[i][j].flag)
		{
			mlx_pixel_put(mlx, win, posit[i][j].x_iso + 150, posit[i][j].y_iso + 50, 0xFFFFFF);
			j++;
		}
		printf("\n");
		i++;
	}
	mlx_loop(mlx);
	//printf("%f",arg[9][3].x_iso);
	free_arr(posit);
	return (0);
}
*/
