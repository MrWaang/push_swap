#include "push_swap.h"

t_pslist	*init_stack(int capacity)
{
	t_pslist	*stack;

	stack = ft_calloc(sizeof(t_pslist), 1);
	if (!stack)
		return (NULL);
	stack->tab = ft_calloc(sizeof(int), capacity);
	if (!stack->tab)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->size_max = capacity;
	return (stack);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
	str = NULL;
}

static void	free_stacks_two(t_pslist *stack_b, int ac, char **args)
{
	if (stack_b)
	{
		if (stack_b->tab)
		{
			free(stack_b->tab);
			stack_b->tab = NULL;
		}
		free(stack_b);
		stack_b = NULL;
	}
	if (ac == 2)
		ft_free(args);
}

void	free_stacks(t_pslist *stack_a, t_pslist *stack_b, int ac, char **args)
{
	if (stack_a)
	{
		if (stack_a->tab)
		{
			free(stack_a->tab);
			stack_a->tab = NULL;
		}
		free(stack_a);
		stack_a = NULL;
	}
	free_stacks_two(stack_b, ac, args);
}

void	push_head(t_pslist *stack_a, int value)
{
	if (stack_a->size_max > stack_a->size)
	{
		stack_a->tab[stack_a->size] = value;
		stack_a->size++;
	}
}
