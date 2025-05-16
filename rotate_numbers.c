#include "push_swap.h"
#include <libft/libft.h>

void	rotate_stack(t_pslist *stack, char *ist)
{
	int	v;

	if (ft_strcmp(ist, "rotate") == 0)
	{
		v = stack->tab[0];
		ft_memmove(stack->tab, stack->tab + 1, sizeof(int) * (stack->size - 1));
		stack->tab[stack->size - 1] = v;
	}
	else if (ft_strcmp(ist, "reverse_rotate") == 0)
	{
		v = stack->tab[stack->size - 1];
		memmove(stack->tab + 1, stack->tab, sizeof(int) * (stack->size - 1));
		stack->tab[0] = v;
	}
}

void	rotate_part_one(t_pslist *stack_a, t_pslist *stack_b, char *ist)
{
	if (ft_strcmp(ist, "ra") == 0)
	{
		ft_printf("ra\n");
		rotate_stack(stack_a, "rotate");
	}
	else if (ft_strcmp(ist, "rb") == 0)
	{
		ft_printf("rb\n");
		rotate_stack(stack_b, "rotate");
	}
	else if (ft_strcmp(ist, "rr") == 0)
	{
		ft_printf("rr\n");
		rotate_stack(stack_a, "rotate");
		rotate_stack(stack_b, "rotate");
	}
}

void	rotate_part_two(t_pslist *stack_a, t_pslist *stack_b, char *ist)
{
	if (ft_strcmp(ist, "rra") == 0)
	{
		ft_printf("rra\n");
		rotate_stack(stack_a, "reverse_rotate");
	}
	else if (ft_strcmp(ist, "rrb") == 0)
	{
		ft_printf("rrb\n");
		rotate_stack(stack_b, "reverse_rotate");
	}
	else if (ft_strcmp(ist, "rrr") == 0)
	{
		ft_printf("rrr\n");
		rotate_stack(stack_a, "reverse_rotate");
		rotate_stack(stack_b, "reverse_rotate");
	}
}
