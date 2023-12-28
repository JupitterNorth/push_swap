/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:14 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/27 16:20:06 by gneto-co         ###   ########.fr       */
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

static int	ft_algorithm_2A(t_list **stack_A, t_list **stack_B, int half, int size, int	modo)
{
	t_node_data	*data_A0;
	t_node_data	*data_A1;
	t_node_data	*data_A_min;
	int			moves;

	ft_load_data(*stack_A, &data_A0, &data_A1);
	moves = 0;
	
	if (modo == 1)
		data_A_min = ft_get_smallest_element(*stack_A, size);
	else if (modo == 2)
		data_A_min = ft_get_higher_element(*stack_A, size);
		
	// se houver pelo menos dois elementos
	if ((*stack_A)->next)
	{
		while (data_A0 != data_A_min)
		{
			if (modo == 1)
				data_A_min = ft_get_smallest_element(*stack_A, size);
			else if (modo == 2)
				data_A_min = ft_get_higher_element(*stack_A, size);
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


// algorithm 2
// version 1.1

int	ft_algorithm_2(t_list **stack_A, t_list **stack_B, int size, int modo)
{
	int moves;
	int half;
	int	i;
	
	moves = 0;
	i = 0;
	while (i < size)
	{
		half = (ft_lstsize(*stack_A)) / 2;
		moves += ft_algorithm_2A(&(*stack_A), &(*stack_B), half, size, modo);
		i++;
	}
	// ft_table_stacks((*stack_A), (*stack_B));
	// getchar();
	if (modo == 1)
	{
		while (i)
		{
			moves += ft_execute_operation("pa", &(*stack_A), &(*stack_B));
			i--;
		}
	}
	// ft_table_stacks((*stack_A), (*stack_B));
	// getchar();
	return (moves);
}
// modo 1
//  stack_A passa para stack_B em ordem invertida
//  e regressa ao stack_A ordenado
// modo 2
//  stack_A passa para o stack_B ordenado
