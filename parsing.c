/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:21:15 by mforest-          #+#    #+#             */
/*   Updated: 2025/02/04 19:00:13 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <libft/libft.h>

char	**parse_args(int argc, char **argv, long *count)
{
	char	**args;

	args = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
		{
			ft_printf("\033[1;91mError\n");
			exit(-1);
		}
		while (args[*count])
			(*count)++;
	}
	else
	{
		args = &argv[1];
		*count = argc - 1;
	}
	return (args);
}

int	parsing(int argc, char **argv)
{
	int		i;
	char	**array_tmp;

	i = 0;
	if (argc == 2)
		array_tmp = ft_split(argv[1], ' ');
	else
		array_tmp = argv + 1;
	while (array_tmp[i])
	{
		if (ft_atoi(array_tmp[i]) < -2147483648
			|| ft_atoi(array_tmp[i]) > 2147483647
			|| check_nbr(array_tmp) != 0
			|| check_entries(array_tmp) != 0)
		{
			if (argc == 2)
				ft_free(array_tmp);
			return (-1);
		}
		i++;
	}
	if (argc == 2)
		ft_free(array_tmp);
	return (0);
}
