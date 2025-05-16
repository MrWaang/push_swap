/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:37:37 by mforest-          #+#    #+#             */
/*   Updated: 2025/02/04 20:34:40 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	long		i;
	long		arg_count;
	char		**args;
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	i = 0;
	arg_count = 0;
	args = parse_args(argc, argv, &arg_count);
	stack_a = init_stack(arg_count);
	stack_b = init_stack(arg_count);
	if (!stack_a || !stack_b || parsing(argc, argv) != 0)
	{
		free_stacks(stack_a, stack_b, argc, args);
		return (ft_printf("Error\n"));
	}
	while (i < arg_count)
		push_head(stack_a, ft_atoi(args[i++]));
	if (sorting_algorithm(stack_a, stack_b, arg_count) != 0)
	{
		free_stacks(stack_a, stack_b, argc, args);
		return (-1);
	}
	free_stacks(stack_a, stack_b, argc, args);
	return (0);
}
