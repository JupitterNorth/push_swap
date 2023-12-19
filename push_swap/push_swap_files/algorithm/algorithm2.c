/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:14 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/05 12:08:47 by gneto-co         ###   ########.fr       */
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

// algorithm 2
// version 1.1

int	ft_algorithm_2A(t_list **stack_A, t_list **stack_B, int half)
{
	t_node_data	*data_A0;
	t_node_data	*data_A1;
	t_node_data	*data_A_min;
	int			moves;

	ft_load_data(*stack_A, &data_A0, &data_A1);
	moves = 0;
	
	data_A_min = ft_get_smallest_element(*stack_A);
	//se houver pelo menos dois elementos
	if ((*stack_A)->next)
	{
		while (data_A0 != data_A_min)
		{
			data_A_min = ft_get_smallest_element(*stack_A);
			if (data_A_min->pos < half)
				moves += ft_execute_operation("ra", &(*stack_A), &(*stack_B));
			else
				moves += ft_execute_operation("rra", &(*stack_A), &(*stack_B));
			ft_load_data(*stack_A, &data_A0, &data_A1);
		}
	}
	moves += ft_execute_operation("pb", &(*stack_A), &(*stack_B));
	return (moves);
}
int	ft_algorithm_2B(t_list **stack_A, t_list **stack_B)
{
	return (ft_execute_operation("pa", &(*stack_A), &(*stack_B)));
}
