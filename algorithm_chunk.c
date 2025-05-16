/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:22:33 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/24 00:50:49 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Determine le nombre de chunks en fonction de la taille de stack_a */
static int	determine_chunk_count(t_pslist *stack_a)
{
	if (stack_a->size <= 100)
		return (6);
	return (12);
}

/* Determine la valeur de fin du chunk actuel */
static int	get_chunk_end(int chunk_start, int i, t_chunk_params *params)
{
	if (i == params->chunk_count - 1)
		return (params->max_val);
	return (chunk_start + params->range - 1);
}

/* Compte le nombre d'elements dans le chunk actuel */
static size_t	count_elements_in_chunk(t_pslist *stack_a, int chunk_start,
		int chunk_end)
{
	size_t	count;
	size_t	j;

	count = 0;
	j = 0;
	while (j < stack_a->size)
	{
		if (stack_a->tab[j] >= chunk_start && stack_a->tab[j] <= chunk_end)
			count++;
		j++;
	}
	return (count);
}

/* Traite le chunk en poussant les elements optimaux */
static void	process_chunk(t_pslist *stack_a, t_pslist *stack_b, int chunk_start,
		int chunk_end)
{
	size_t	elements_in_chunk;

	elements_in_chunk = count_elements_in_chunk(stack_a, chunk_start,
			chunk_end);
	while (elements_in_chunk > 0)
	{
		push_optimal_element(stack_a, stack_b, chunk_start, chunk_end);
		elements_in_chunk--;
	}
}

void	first_phase_push_b(t_pslist *stack_a, t_pslist *stack_b, int min_val,
		int max_val)
{
	t_chunk_params	params;
	int				i;
	int				chunk_start;
	int				chunk_end;

	params.chunk_count = determine_chunk_count(stack_a);
	params.range = (((max_val - min_val) + params.chunk_count)
			/ params.chunk_count);
	params.max_val = max_val;
	i = 0;
	while (i < params.chunk_count && stack_a->size > 0)
	{
		chunk_start = min_val + (i * params.range);
		chunk_end = get_chunk_end(chunk_start, i, &params);
		process_chunk(stack_a, stack_b, chunk_start, chunk_end);
		i++;
	}
}
