#include "../includes/push_swap.h"

void	sort_push(t_pslist *stack_a, t_pslist *stack_b, char *ist)
{
	if (ft_strcmp(ist, "pa") == 0)
		push_a(stack_a, stack_b);
	if (ft_strcmp(ist, "pb") == 0)
		push_b(stack_a, stack_b);
}

void	rotate(t_pslist *stack_a, t_pslist *stack_b, char *ist)
{
	rotate_part_one(stack_a, stack_b, ist);
	rotate_part_two(stack_a, stack_b, ist);
}

void	sort_swap(t_pslist *stack_a, t_pslist *stack_b, char *ist)
{
	if (ft_strcmp(ist, "sa") == 0)
	{
		ft_swap(&stack_a->tab[0], &stack_a->tab[1]);
		ft_printf("sa\n");
	}
	else if (ft_strcmp(ist, "sb") == 0)
	{
		ft_swap(&stack_b->tab[0], &stack_b->tab[1]);
		ft_printf("sb\n");
	}
	else if (ft_strcmp(ist, "ss") == 0)
	{
		ft_swap(&stack_a->tab[0], &stack_a->tab[1]);
		ft_swap(&stack_b->tab[0], &stack_b->tab[1]);
		ft_printf("ss\n");
	}
}
