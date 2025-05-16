/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 02:18:11 by mforest-          #+#    #+#             */
/*   Updated: 2025/02/05 23:57:12 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_and_push(t_pslist *a, t_pslist *b, unsigned int best_index)
{
	if (best_index <= a->size / 2)
	{
		while (best_index > 0)
		{
			sorting(a, b, "ra");
			best_index--;
		}
	}
	else
	{
		while (best_index < a->size)
		{
			sorting(a, b, "rra");
			best_index++;
		}
	}
	sorting(a, b, "pb");
}

void	push_optimal_element(t_pslist *a, t_pslist *b, int chunk_start,
		int chunk_end)
{
	int	best_index;

	best_index = find_best_index(a, chunk_start, chunk_end);
	if (best_index == -1)
		return ;
	rotate_and_push(a, b, best_index);
}

void	bucket_sort(t_pslist *stack_a, t_pslist *stack_b)
{
	int	min_val;
	int	max_val;

	get_min_max(stack_a, &min_val, &max_val);
	first_phase_push_b(stack_a, stack_b, min_val, max_val);
	second_phase_push_a(stack_a, stack_b);
}
