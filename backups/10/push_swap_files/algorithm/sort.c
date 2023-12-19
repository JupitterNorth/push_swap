/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:10:01 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/19 19:42:57 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// algorithm 1
static int	ft_sort_1(t_list **stack_A, t_list **stack_B)
{
	int	moves;
	int half;

	(void)ft_table_stacks;
	moves = 0;
	half = (ft_lstsize(*stack_A)-1) / 2;
	while (!stack_in_order(*stack_A) || *stack_B)
	{
		// half /= 2;
		while (*stack_A)
		{
			moves += ft_algorithm_1A(&(*stack_A), &(*stack_B), half);
		}
		// ft_table_stacks((*stack_A), (*stack_B));
		// getchar();
		while (*stack_B)
		{
			moves += ft_algorithm_1B(&(*stack_A), &(*stack_B), half);
		}
		// ft_table_stacks((*stack_A), (*stack_B));
		// getchar();
	}
	return (moves);
}

// algorithm 2
int	ft_sort_2(t_list **stack_A, t_list **stack_B)
{
	int moves;
	int half;

	(void)ft_table_stacks;
	moves = 0;
	while (!stack_in_order(*stack_A) || *stack_B)
	{
		while (*stack_A)
		{
			half = (ft_lstsize(*stack_A)) / 2;
			moves += ft_algorithm_2A(&(*stack_A), &(*stack_B), half);
		}
		// ft_table_stacks((*stack_A), (*stack_B));
		// getchar();
		while (*stack_B)
		{
			moves += ft_algorithm_2B(&(*stack_A), &(*stack_B));
		}
		// ft_table_stacks((*stack_A), (*stack_B));
		// getchar();
	}
	return (moves);
}

// true sort
int	ft_sort_stack(t_list **stack_A, t_list **stack_B)
{
	(void)ft_table_stacks;
	(void)ft_sort_1;
	(void)ft_sort_2;

	if (ft_lstsize(*stack_A) == 2)
		return (ft_execute_operation("sa", &(*stack_A), &(*stack_B)));
	else if (ft_lstsize(*stack_A) == 3)
		return (ft_algorithm_4A(&(*stack_A), &(*stack_B)));
	else if (ft_lstsize(*stack_A) <= 5)
		return (ft_algorithm_5A(&(*stack_A), &(*stack_B)));
	else
		return (ft_sort_2(&(*stack_A), &(*stack_B)));
	
	return (0);
}