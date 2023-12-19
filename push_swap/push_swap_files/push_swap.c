/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:11:03 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/19 19:41:49 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_swap(int *nb_list, int size)
{
	t_list *stack_A;
	t_list *stack_B;
	int moves;
	
	moves = 0;
	// create stacks A and B
	stack_A = ft_stack_creation(nb_list, size);
	stack_B = ft_stack_creation(NULL, 0);

	// show original stacks
	ft_putstr("\nOriginal Stack");
	ft_table_stacks(stack_A, stack_B);

	// getchar();

	// execute algorithm if stack is not in order
	if (!stack_in_order(stack_A))
		moves = ft_sort_stack(&stack_A, &stack_B);

	(void)ft_table_stacks;
	// show final stack
	ft_table_stacks(stack_A, stack_B);
	
	ft_putstr("\nFinal Stack -");
	if (stack_in_order(stack_A))
		ft_putstr("\033[32m Correct Order\n\033[0m");
	else
		ft_putstr("\033[31m Wrong Order\n\033[0m");
		
		
	
	printf("\n\nMoves: %d\n\n", moves);

	// free stacks
	ft_lstclear(&stack_A, free);
	ft_lstclear(&stack_B, free);

	return (moves);
}