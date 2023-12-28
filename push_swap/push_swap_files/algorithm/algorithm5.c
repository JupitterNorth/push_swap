/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:20:21 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/28 16:23:12 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_load_data(t_list *stack, t_node_data **data_0,
		t_node_data **data_1)
{
	if (stack)
		(*data_0) = stack->content;
	if (stack->next)
		(*data_1) = stack->next->content;
}

// algorithm 5
// version: 1.0
// sort a stacks with only 4 or 5 elements 
int	ft_algorithm_5(t_list **stack_A, t_list **stack_B)
{
	t_node_data	*data_A0;
	t_node_data	*data_A1;
	t_node_data	*data_B0;
	t_node_data	*data_B1;
	int			moves;
    int         size;

    size = ft_lstsize(*stack_A);    
	moves = 0;
	ft_load_data(*stack_A, &data_A0, &data_A1);
    while (ft_lstsize(*stack_B) < (size - 3))
    {
		ft_load_data(*stack_A, &data_A0, &data_A1);
        if (data_A0->ele > 2)
            moves += ft_execute_operation("pb", &(*stack_A), &(*stack_B), 1);
        else
            moves += ft_execute_operation("ra", &(*stack_A), &(*stack_B), 1);
    }
    // organizar stack agora que tem só 3 elementos
   	ft_algorithm_4(&(*stack_A), &(*stack_B));
		
	ft_load_data(*stack_B, &data_B0, &data_B1);
    if (ft_lstsize(*stack_B) > 1 && data_B0->ele < data_B1->ele)
	{
        moves += ft_execute_operation("sb", &(*stack_A), &(*stack_B), 1);	
	}
	while (*stack_B)
	{
		moves += ft_execute_operation("pa", &(*stack_A), &(*stack_B), 1);	
	}
	while (!stack_in_order(*stack_A))
	{
		moves += ft_execute_operation("ra", &(*stack_A), &(*stack_B), 1);	
	}
	
	return (moves);
}
