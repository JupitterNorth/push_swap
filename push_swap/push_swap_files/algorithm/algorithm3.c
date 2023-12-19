/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:14 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/06 11:25:03 by gneto-co         ###   ########.fr       */
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

// algorithm 3
// version 1.0

int	ft_algorithm_3A(t_list **stack_A, t_list **stack_B)
{
	t_node_data	*data_A0;
	t_node_data	*data_A1;
	static int	ele_min;
	int			moves;

	ft_load_data(*stack_A, &data_A0, &data_A1);
	moves = 0;
	ele_min = 0;
	
	if (element_on_stack(ele_min, *stack_B))
		moves += ft_algorithm_3B(&(*stack_A),&(*stack_B), ele_min);

	while (data_A0->ele != ele_min)
	{
		// executa se o ele_min estiver no A
		ft_load_data(*stack_A, &data_A0, &data_A1);
	}
	ele_min++;
	moves += ft_execute_operation("ra", &(*stack_A), &(*stack_B));
	return (moves);
}
int	ft_algorithm_3B(t_list **stack_A, t_list **stack_B, int ele_min)
{
	t_node_data	*data_B0;
	t_node_data	*data_B1;
	int			moves;
	int			half;

	half = ft_lstsize(*stack_B) / 2;

	ft_load_data(*stack_A, &data_B0, &data_B1);
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
	moves += ft_execute_operation("pa", &(*stack_A), &(*stack_B));
	return (moves);
}
