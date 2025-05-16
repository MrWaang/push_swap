#include "push_swap.h"

int	stack_is_sort(t_pslist *stack_a)
{
	size_t	i;

	i = 0;
	if (!stack_a || !stack_a->tab)
		return (-1);
	if (stack_a->size < 2)
		return (0);
	while (i < stack_a->size - 1)
	{
		if (stack_a->tab[i] > stack_a->tab[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

void	move_max_to_b(t_pslist *stack_a, t_pslist *stack_b)
{
	int	max_index;
	int	size;

	max_index = get_max_index(stack_a);
	size = stack_a->size;
	if (max_index <= size / 2)
	{
		while (max_index-- > 0)
			sorting(stack_a, stack_b, "ra");
	}
	else
	{
		max_index = size - max_index;
		while (max_index-- > 0)
			sorting(stack_a, stack_b, "rra");
	}
	sorting(stack_a, stack_b, "pb");
}

void	find_max_val_and_pos(t_pslist *stack_b, int *max_val, size_t *max_pos)
{
	size_t	i;

	*max_val = stack_b->tab[0];
	*max_pos = 0;
	i = 1;
	while (i < stack_b->size)
	{
		if (stack_b->tab[i] > *max_val)
		{
			*max_val = stack_b->tab[i];
			*max_pos = i;
		}
		i++;
	}
}
