#include "push_swap.h"

/* Effectue les rotations necessaires sur stack_b */
static void	rotate_stack_b(t_pslist *stack_a, t_pslist *stack_b, size_t max_pos)
{
	if (max_pos <= stack_b->size / 2)
	{
		while (max_pos--)
			sorting(stack_a, stack_b, "rb");
	}
	else
	{
		while (max_pos < stack_b->size)
		{
			sorting(stack_a, stack_b, "rrb");
			max_pos++;
		}
	}
}

void	second_phase_push_a(t_pslist *stack_a, t_pslist *stack_b)
{
	int		max_val;
	size_t	max_pos;

	while (stack_b->size > 0)
	{
		find_max_val_and_pos(stack_b, &max_val, &max_pos);
		rotate_stack_b(stack_a, stack_b, max_pos);
		sorting(stack_a, stack_b, "pa");
	}
}
