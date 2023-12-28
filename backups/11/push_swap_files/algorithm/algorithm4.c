/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:35:47 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/27 14:45:29 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_load_data(t_list *stack, t_node_data **data_0,
		t_node_data **data_1, t_node_data **data_2)
{
	if (stack)
		(*data_0) = stack->content;
	if (stack->next)
		(*data_1) = stack->next->content;
    if (stack->next->next)
		(*data_2) = stack->next->next->content;
}

// algorithm 1
// version: 1.0
// sort a stacks with only 3 elements 
int	ft_algorithm_4(t_list **stack_A, t_list **stack_B)
{
	t_node_data	*data_A0;
	t_node_data	*data_A1;
	t_node_data	*data_A2;
	int			moves;

	ft_load_data(*stack_A, &data_A0, &data_A1, &data_A2);
	moves = 0;
	if (stack_in_order(*stack_A))
		return 0;
    if(data_A1->ele == 1 || data_A0->ele == 2)
	    moves += ft_execute_operation("ra", &(*stack_A), &(*stack_B));
    else if(data_A1->ele == 2)
	    moves += ft_execute_operation("rra", &(*stack_A), &(*stack_B));
	ft_load_data(*stack_A, &data_A0, &data_A1, &data_A2);
    if (data_A0->ele > data_A1->ele)
		moves += ft_execute_operation("sa", &(*stack_A), &(*stack_B));
	return (moves);
}