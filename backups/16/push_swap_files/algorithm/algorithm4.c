/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:35:47 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/02 18:17:15 by gneto-co         ###   ########.fr       */
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
int	ft_algorithm_4(t_list **stack_a, t_list **stack_b)
{
	t_node_data	*data_a0;
	t_node_data	*data_a1;
	t_node_data	*data_a2;
	int			moves;

	ft_load_data(*stack_a, &data_a0, &data_a1, &data_a2);
	moves = 0;
	if (stack_in_order(*stack_a))
		return (0);
	if (data_a1->ele == 1 || data_a0->ele == 2)
		moves += ft_execute_operation("ra", &(*stack_a), &(*stack_b), 1);
	else if (data_a1->ele == 2)
		moves += ft_execute_operation("rra", &(*stack_a), &(*stack_b), 1);
	ft_load_data(*stack_a, &data_a0, &data_a1, &data_a2);
	if (data_a0->ele > data_a1->ele)
		moves += ft_execute_operation("sa", &(*stack_a), &(*stack_b), 1);
	return (moves);
}
