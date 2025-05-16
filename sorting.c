#include "../includes/push_swap.h"
#include <libft/libft.h>

int	sorting(t_pslist *stack_a, t_pslist *stack_b, char *ist)
{
	sort_swap(stack_a, stack_b, ist);
	sort_push(stack_a, stack_b, ist);
	rotate(stack_a, stack_b, ist);
	return (0);
}

int	sorting_algorithm(t_pslist *stack_a, t_pslist *stack_b, int num)
{
	if (stack_is_sort(stack_a) == 0)
		return (-1);
	if (num == 2)
		two_numbers_sort(stack_a, stack_b);
	if (num == 3)
		three_numbers_sort(stack_a, stack_b);
	if (num == 4)
		four_numbers_sort(stack_a, stack_b);
	if (num == 5)
		five_numbers_sort(stack_a, stack_b);
	if (num > 5)
		bucket_sort(stack_a, stack_b);
	return (0);
}
