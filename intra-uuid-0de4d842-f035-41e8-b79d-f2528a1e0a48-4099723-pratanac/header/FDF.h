/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:27:49 by pratanac          #+#    #+#             */
/*   Updated: 2022/04/18 21:05:34 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define WIN_H			640
# define WIN_W			1280

# define KEY_LEFT		65361
# define KEY_UP			65362
# define KEY_RIGHT		65363
# define KEY_DOWN		65364
# define KEY_ESC		0xFF1B
# define X_SCALE		10
# define Y_SCALE		10
# define Z_SCALE		10

typedef struct s_posit
{
	int		x;
	int		y;
	int		z;
	double	x_iso;
	double	y_iso;
	int		color;
	char	flag;
}	t_posit;

typedef struct s_size
{
	double	min_x;
	double	min_y;
	double	max_x;
	double	max_y;
	double	max_z;
}	t_size;

typedef struct s_adj
{
	double	offset_x;
	double	offset_y;
	double	scale;
}	t_adj;

typedef struct s_draw
{
	double	s_x;
	double	s_y;
	double	e_x;
	double	e_y;
	int		s_c;
	int		e_c;
}	t_draw;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_posit	**posit;
	int		z;
}	t_var;

/* 0_get_next_line */
char	*get_next_line(int fd);

/* 1_set_utils */
void	free_split(char **split);
void	free_arr(t_posit **arr);
int		ft_len_arr(t_posit **arr);
int		ft_len_split(char **split);
int		ft_len_posit(t_posit *posit);

/* 2_set_utils */
t_posit	**join_arr(t_posit **arr, t_posit *sub_arr);
t_posit	*create_arr(char *line, int row);
t_posit	**set_input(char **argv);

/* 3_convert_posit */
t_posit	**convert_iso(t_posit **posit);
t_posit	**convert_fv(t_posit **fv);
t_posit	**rotate_arr(t_posit **posit);
t_posit	**scaling_arr(t_posit **posit, double scale);
t_posit	**offset_arr(t_posit **posit, double offset_x, double offset_y);

/* 4_adjust_posit */
t_size	get_size(t_posit **posit);
t_adj	get_adjust(t_posit **posit);

/* 5_drawing */
t_draw	fill_target(t_posit start, t_posit end);
int		drawing(void *mlx, void *win, t_draw t);
int		draw_horizon(void *mlx, void *win, t_posit **posit);
int		draw_vertical(void *mlx, void *win, t_posit **posit);

/* 6_event */
int		destroy(t_var *param);
int		keyboard_input(int keynote, t_var *param);

/* 7_bonus_stuff */
int		draw_horizon_bonus(void *mlx, void *win, t_posit **posit, int max_z);
int		draw_vertical_bonus(void *mlx, void *win, t_posit **posit, int max_z);
int		expose_hook(t_var *param);
#endif
