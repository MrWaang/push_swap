#include "push_swap.h"

int	get_max_index(t_pslist *stack_a)
{
	int		max_index;
	size_t	i;

	max_index = 0;
	i = 1;
	while (i < stack_a->size)
	{
		if (stack_a->tab[i] > stack_a->tab[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

int	get_min_index(t_pslist *stack_a)
{
	int		min_index;
	size_t	i;

	min_index = 0;
	i = 1;
	while (i < stack_a->size)
	{
		if (stack_a->tab[i] < stack_a->tab[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	get_min_max(t_pslist *stack, int *min, int *max)
{
	size_t	i;

	*min = stack->tab[0];
	*max = stack->tab[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->tab[i] < *min)
			*min = stack->tab[i];
		if (stack->tab[i] > *max)
			*max = stack->tab[i];
		i++;
	}
}

int	get_target_position(int value, t_pslist *stack)
{
	size_t	i;
	int		min_val;
	int		max_val;
	int		min_pos;
	int		max_pos;

	get_min_max(stack, &min_val, &max_val);
	min_pos = get_min_index(stack);
	max_pos = get_max_index(stack);
	if (value < min_val)
		return (min_pos);
	if (value > max_val)
		return ((max_pos + 1) % stack->size);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->tab[i] < value && value < stack->tab[i + 1])
			return (i + 1);
		i++;
	}
	return (0);
}

int	find_best_index(t_pslist *a, int chunk_start, int chunk_end)
{
	int		best_index;
	int		best_score;
	size_t	i;
	int		score;

	best_index = -1;
	best_score = a->size;
	i = 0;
	while (i < a->size)
	{
		if (a->tab[i] >= chunk_start && a->tab[i] <= chunk_end)
		{
			if (i <= a->size / 2)
				score = i;
			else
				score = (a->size - i);
			if (score < best_score)
			{
				best_score = score;
				best_index = i;
			}
		}
		i++;
	}
	return (best_index);
}
