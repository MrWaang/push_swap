#include "push_swap.h"

void	two_numbers_sort(t_pslist *stack_a, t_pslist *stack_b)
{
	if (stack_a->tab[0] > stack_a->tab[1])
		sorting(stack_a, stack_b, "sa");
}

void	three_numbers_sort(t_pslist *stack_a, t_pslist *stack_b)
{
	if (stack_a->tab[get_max_index(stack_a)] == stack_a->tab[0])
		sorting(stack_a, stack_b, "ra");
	if (stack_a->tab[0] > stack_a->tab[1])
		sorting(stack_a, stack_b, "sa");
	if (stack_is_sort(stack_a) != 0)
		sorting(stack_a, stack_b, "rra");
	if (stack_a->tab[0] > stack_a->tab[1])
		sorting(stack_a, stack_b, "sa");
}

void	four_numbers_sort(t_pslist *stack_a, t_pslist *stack_b)
{
	move_max_to_b(stack_a, stack_b);
	three_numbers_sort(stack_a, stack_b);
	sorting(stack_a, stack_b, "pa");
	sorting(stack_a, stack_b, "ra");
}

void	five_numbers_sort(t_pslist *stack_a, t_pslist *stack_b)
{
	move_max_to_b(stack_a, stack_b);
	move_max_to_b(stack_a, stack_b);
	three_numbers_sort(stack_a, stack_b);
	sorting(stack_a, stack_b, "pa");
	sorting(stack_a, stack_b, "ra");
	sorting(stack_a, stack_b, "pa");
	sorting(stack_a, stack_b, "ra");
}
