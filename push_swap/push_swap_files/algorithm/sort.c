/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:10:01 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/28 16:30:14 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sort_stack(t_list **stack_A, t_list **stack_B)
{
	int		chunk_size;
	int		best_chunk_size;
	int		moves_record;
	int		moves;
	int		stack_size;
	t_list	*stack_test_A;
	t_list	*stack_test_B;
	
	
	if (ft_lstsize(*stack_A) == 2)
		return (ft_execute_operation("sa", &(*stack_A), &(*stack_B), 1));
	else if (ft_lstsize(*stack_A) == 3)
		return (ft_algorithm_4(&(*stack_A), &(*stack_B)));
	else if (ft_lstsize(*stack_A) <= 5)
		return (ft_algorithm_5(&(*stack_A), &(*stack_B)));
	else if (ft_lstsize(*stack_A) <= 50)
		return(ft_algorithm_2(&(*stack_A), &(*stack_B), ft_lstsize(*stack_A), 1, 1));
	else if (ft_lstsize(*stack_A) <= 100)
	{
		stack_size = ft_lstsize(*stack_A);
		chunk_size = 1;
		best_chunk_size = 0;
		while (chunk_size < stack_size / 2)
		{
			printf("a");
			stack_test_A = *stack_A;
			stack_test_B = *stack_B;
			
			moves = ft_algorithm_6(&stack_test_A, &stack_test_B, chunk_size, 0);
			
			if (moves_record == 0)
				moves_record = moves;
			else if (moves < moves_record)
			{
				moves_record = moves;
				best_chunk_size = chunk_size;
			}
			
			chunk_size++;
		}
		return (ft_algorithm_6(&(*stack_A), &(*stack_B), best_chunk_size, 1));
	}
	
	return (0);
}
