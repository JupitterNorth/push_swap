/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:20:21 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/02 18:13:53 by gneto-co         ###   ########.fr       */
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

static int	ft_algorithm_5a(t_list **stack_a, t_list **stack_b)
{
	t_node_data	*data_b0;
	t_node_data	*data_b1;
	int			moves;

	moves = 0;
	ft_load_data(*stack_b, &data_b0, &data_b1);
	if (ft_lstsize(*stack_b) > 1 && data_b0->ele < data_b1->ele)
		moves += ft_execute_operation("sb", &(*stack_a), &(*stack_b), 1);
	while (*stack_b)
		moves += ft_execute_operation("pa", &(*stack_a), &(*stack_b), 1);
	while (!stack_in_order(*stack_a))
		moves += ft_execute_operation("ra", &(*stack_a), &(*stack_b), 1);
	return (moves);
}

// algorithm 5
// version: 1.0
// sort a stacks with only 4 or 5 elements
int	ft_algorithm_5(t_list **stack_a, t_list **stack_b)
{
	t_node_data	*data_a0;
	t_node_data	*data_a1;
	int			moves;
	int			size;

	size = ft_lstsize(*stack_a);
	moves = 0;
	ft_load_data(*stack_a, &data_a0, &data_a1);
	while (ft_lstsize(*stack_b) < (size - 3))
	{
		ft_load_data(*stack_a, &data_a0, &data_a1);
		if (data_a0->ele > 2)
			moves += ft_execute_operation("pb", &(*stack_a), &(*stack_b), 1);
		else
			moves += ft_execute_operation("ra", &(*stack_a), &(*stack_b), 1);
	}
	ft_algorithm_4(&(*stack_a), &(*stack_b));
	moves += ft_algorithm_5a(&(*stack_a), &(*stack_b));
	return (moves);
}
