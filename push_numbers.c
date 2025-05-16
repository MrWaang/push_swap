/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 03:50:22 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/19 21:48:14 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_pslist *stack_a, t_pslist *stack_b)
{
	int					temp;
	unsigned long int	i;

	if (stack_b->size == 0)
		return ;
	temp = stack_b->tab[0];
	i = stack_a->size;
	while (i > 0)
	{
		stack_a->tab[i] = stack_a->tab[i - 1];
		i--;
	}
	stack_a->tab[0] = temp;
	stack_a->size++;
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		i++;
	}
	stack_b->size--;
	ft_printf("pa\n");
}

void	push_b(t_pslist *stack_a, t_pslist *stack_b)
{
	int					temp;
	unsigned long int	i;

	if (stack_a->size == 0)
		return ;
	temp = stack_a->tab[0];
	i = stack_b->size;
	while (i > 0)
	{
		stack_b->tab[i] = stack_b->tab[i - 1];
		i--;
	}
	stack_b->tab[0] = temp;
	stack_b->size++;
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
	stack_a->tab[stack_a->size - 1] = 0;
	stack_a->size--;
	ft_printf("pb\n");
}
