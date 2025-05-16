/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:38:18 by mforest-          #+#    #+#             */
/*   Updated: 2025/02/04 20:34:27 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_pslist
{
	int		*tab;
	size_t	size;
	size_t	size_max;
}			t_pslist;

typedef struct s_chunk_params
{
	int		chunk_count;
	long	range;
	int		max_val;
}			t_chunk_params;

t_pslist	*init_stack(int capacity);
void		push_head(t_pslist *stack, int value);
void		sort_swap(t_pslist *stack_a, t_pslist *stack_b, char *ist);
void		sort_push(t_pslist *stack_a, t_pslist *stack_b, char *ist);
void		rotate(t_pslist *stack_a, t_pslist *stack_b, char *ist);
void		rotate_part_one(t_pslist *stack_a, t_pslist *stack_b, char *ist);
void		rotate_part_two(t_pslist *stack_a, t_pslist *stack_b, char *ist);
void		rotate_stack(t_pslist *stack, char *ist);
int			sorting(t_pslist *stack_a, t_pslist *stack_b, char *ist);
int			sorting_algorithm(t_pslist *stack_a, t_pslist *stack_b, int num);
void		two_numbers_sort(t_pslist *stack_a, t_pslist *stack_b);
void		three_numbers_sort(t_pslist *stack_a, t_pslist *stack_b);
void		four_numbers_sort(t_pslist *stack_a, t_pslist *stack_b);
void		five_numbers_sort(t_pslist *stack_a, t_pslist *stack_b);
void		push_a(t_pslist *stack_a, t_pslist *stack_b);
void		push_b(t_pslist *stack_a, t_pslist *stack_b);
int			stack_is_sort(t_pslist *stack);
void		move_max_to_b(t_pslist *stack_a, t_pslist *stack_b);
int			get_target_position(int value, t_pslist *stack);
void		first_phase_push_b(t_pslist *stack_a, t_pslist *stack_b,
				int min_val, int max_val);
void		second_phase_push_a(t_pslist *stack_a, t_pslist *stack_b);
void		push_optimal_element(t_pslist *a, t_pslist *b, int chunk_start,
				int chunk_end);
int			find_best_index(t_pslist *a, int chunk_start, int chunk_end);
void		get_min_max(t_pslist *stack, int *min, int *max);
int			get_max_index(t_pslist *stack_a);
int			get_min_index(t_pslist *stack_a);
int			check_entries(char **argv);
int			check_nbr(char **argv);
char		**parse_args(int ac, char **av, long *count);
int			parsing(int argc, char **argv);
void		find_max_val_and_pos(t_pslist *stack_b, int *max_val,
				size_t *max_pos);
void		bucket_sort(t_pslist *stack_a, t_pslist *stack_b);
void		free_stacks(t_pslist *stack_a, t_pslist *stack_b, int ac,
				char **args);
void		ft_free(char **str);

#endif
