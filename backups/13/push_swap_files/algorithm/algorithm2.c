/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:14 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/29 22:41:10 by gneto-co         ###   ########.fr       */
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

static int	ft_algorithm_2A(t_list **stack_A, t_list **stack_B, int half, int size, int	modo, int exe)
{
	t_node_data	*data_A0;
	t_node_data	*data_A1;
	t_node_data	*data_Aa;
	int			moves;

	ft_load_data(*stack_A, &data_A0, &data_A1);
	moves = 0;
	
	if (modo == 1)
		data_Aa = ft_get_smallest_element(*stack_A, size);
	else if (modo == 2)
		data_Aa = ft_get_higher_element(*stack_A, size);
		
	// if there is at least two elements
	if ((*stack_A)->next)
	{
		while (data_A0 != data_Aa)
		{
			if (modo == 1)
				data_Aa = ft_get_smallest_element(*stack_A, size);
			else if (modo == 2)
				data_Aa = ft_get_higher_element(*stack_A, size);
			if (data_Aa->pos < half)
				moves += ft_execute_operation("ra", &(*stack_A), &(*stack_B), exe);
			else
				moves += ft_execute_operation("rra", &(*stack_A), &(*stack_B), exe);
			ft_load_data(*stack_A, &data_A0, &data_A1);
		}
	}
	moves += ft_execute_operation("pb", &(*stack_A), &(*stack_B), exe);
	return (moves);
}


// algorithm 2
// version 1.1

int	ft_algorithm_2(t_list **stack_A, t_list **stack_B, int size, int modo, int exe)
{
	int moves;
	int half;
	int	i;
	
	moves = 0;
	i = 0;
	while (i < size)
	{
		half = (ft_lstsize(*stack_A)) / 2;
		moves += ft_algorithm_2A(&(*stack_A), &(*stack_B), half, size, modo, exe);
		i++;
	}
	// ft_table_stacks((*stack_A), (*stack_B));
	// getchar();
	if (modo == 1)
	{
		while (i)
		{
			moves += ft_execute_operation("pa", &(*stack_A), &(*stack_B), exe);
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
