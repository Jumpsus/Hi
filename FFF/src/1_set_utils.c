
#include "libft.h"
#include "FDF.h"

void	free_split(char	**split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_arr(t_posit **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_len_arr(t_posit **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
	{
		i++;
	}
	return (i);
}

int	ft_len_posit(t_posit *posit)
{
	int	i;

	i = 0;
	while (posit[i].flag)
	{
		i++;
	}
	return (i);
}

int	ft_len_split(char **split)
{
	int	i;

	i = 0;
	while(split[i])
		i++;
	return (i);
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
