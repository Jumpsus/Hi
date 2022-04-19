/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_set_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:32:26 by pratanac          #+#    #+#             */
/*   Updated: 2022/04/18 20:34:04 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "FDF.h"

t_posit	**join_arr(t_posit **arr, t_posit *sub_arr)
{
	int		len;
	int		i;
	t_posit	**new_arr;

	i = 0;
	len = ft_len_arr(arr);
	new_arr = ft_calloc(sizeof(t_posit *), len + 2);
	if (!new_arr)
		return (NULL);
	if (!sub_arr)
	{
		free(new_arr);
		return (arr);
	}
	while (i < len)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i] = sub_arr;
	if (arr)
		free(arr);
	return (new_arr);
}

static void	exit_program_with_free(char *line, char **split,t_posit *sub_arr, t_posit **arr)
{
	if (line)
		free(line);
	if (sub_arr)
		free(sub_arr);
	if (split)
		free_split(split);
	if (arr)
		free_arr(arr);
	ft_putstr_fd("Wrong input !! Please check your format \n", 2);
	exit (3);
}

t_posit	*create_arr(char *line, int row, t_posit **arr)
{
	char		**split;
	t_posit		*sub_arr;
	int			i;

	i = 0;
	split = ft_split(line, ' ');
	sub_arr = ft_calloc(sizeof(t_posit), ft_len_split(split) + 1);
	if (!sub_arr)
		return (NULL);
	while (split[i])
	{
		if (!check_input(split[i]))
			exit_program_with_free(line, split, sub_arr, arr);
		sub_arr[i].x = i * X_SCALE;
		sub_arr[i].z = 1 * row * Y_SCALE;
		sub_arr[i].y = -1 * ft_atoi(split[i]) * Z_SCALE;
		sub_arr[i].color = ft_clr_atoi(split[i]);
		sub_arr[i].flag = '1';
		i++;
	}
	free_split(split);
	return (sub_arr);
}

t_posit	**set_input(char **argv)
{
	int			fd;
	t_posit		**arr;
	t_posit		*sub_arr;
	int			row;
	char		*line;

	row = 0;
	arr = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("File Can't Be Opened !! \n", 2);
		exit (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		sub_arr = create_arr(line, row++, arr);
		arr = join_arr(arr, sub_arr);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (arr);
}

/*
#include <stdio.h>
int	main(int argc, char ** argv)
{
	argc = 0;
	t_posit **arg;
	(void) argc;

	arg = set_input(argv);
	printf("%d",arg[9][3].z);

	free_arr(arg);
	return (0);
}
*/
