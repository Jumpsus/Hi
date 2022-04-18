#include "FDF.h"
#include "libft.h"

static t_size	set_worst(void)
{
	t_size  prop;

	prop.min_x = 2147483647;
	prop.min_y = 2147483647;
	prop.max_x = -2147483648;
	prop.max_y = -2147483648;
	prop.max_z = 2147483647;
	return (prop);
}

/* get min max in projection*/
t_size	get_size(t_posit **posit)
{
	t_size	prop;
	int	i;
	int	j;

	i = 0;
	prop = set_worst();
	while (posit[i])
	{
		j = 0;
		while (posit[i][j].flag)
		{
			if (posit[i][j].x_iso > prop.max_x)
				prop.max_x = posit[i][j].x_iso;
			if (posit[i][j].x_iso < prop.min_x)
				prop.min_x = posit[i][j].x_iso;
			if (posit[i][j].y_iso > prop.max_y)
				prop.max_y = posit[i][j].y_iso;
			if (posit[i][j].y_iso < prop.min_y)
				prop.min_y = posit[i][j].y_iso;
			if (posit[i][j].y < prop.max_z)
				prop.max_z = posit[i][j].y;
			j++;
		}
		i++;
	}
	return (prop);
}

/* get adjust for model*/
t_adj	get_adjust(t_posit **posit)
{
	t_adj	adj;
	t_size	prop;
	double	scale_x;
	double	scale_y;

	prop = get_size(posit);
	scale_x = (WIN_W - 100) / fabs(prop.max_x - prop.min_x);
	scale_y = (WIN_H - 100) / fabs(prop.max_y - prop.min_y);
	if (scale_x < scale_y)
		adj.scale = scale_x;
	else
		adj.scale = scale_y;
	adj.offset_x = (-1 * prop.min_x * adj.scale) + (WIN_W - (fabs(prop.max_x - prop.min_x) * adj.scale)) / 2;
	adj.offset_y = (-1 * prop.min_y * adj.scale) + (WIN_H - (fabs(prop.max_y - prop.min_y) * adj.scale)) / 2;
	return (adj);
}
