/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:10:01 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/27 17:05:28 by gneto-co         ###   ########.fr       */
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

// true sort
int	ft_sort_stack(t_list **stack_A, t_list **stack_B)
{
	(void)ft_table_stacks;
	(void)ft_sort_1;
	if (ft_lstsize(*stack_A) == 2)
		return (ft_execute_operation("sa", &(*stack_A), &(*stack_B)));
	else if (ft_lstsize(*stack_A) == 3)
		return (ft_algorithm_4(&(*stack_A), &(*stack_B)));
	else if (ft_lstsize(*stack_A) <= 5)
		return (ft_algorithm_5(&(*stack_A), &(*stack_B)));
	else if (ft_lstsize(*stack_A) <= 50)
		return(ft_algorithm_2(&(*stack_A), &(*stack_B), ft_lstsize(*stack_A), 1));
	else
		return (ft_algorithm_6(&(*stack_A), &(*stack_B)));
	
	return (0);
}