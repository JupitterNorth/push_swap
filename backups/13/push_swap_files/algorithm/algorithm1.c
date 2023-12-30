/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:14 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/28 16:28:03 by gneto-co         ###   ########.fr       */
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

// algorithm 1
// version: 3.0
static int	ft_algorithm_1A(t_list **stack_A, t_list **stack_B, int half)
{
	t_node_data	*data_A0;
	t_node_data	*data_A1;
	int			moves;

	ft_load_data(*stack_A, &data_A0, &data_A1);
	moves = 0;
	if ((*stack_A)->next)
	{
		if (data_A0->ele > half && data_A0->ele > data_A1->ele)
			moves += ft_execute_operation("ra", &(*stack_A), &(*stack_B), 1);
		ft_load_data(*stack_A, &data_A0, &data_A1);
		if (data_A0->ele > data_A1->ele)
			moves += ft_execute_operation("sa", &(*stack_A), &(*stack_B), 1);
	}
	moves += ft_execute_operation("pb", &(*stack_A), &(*stack_B), 1);
	return (moves);
}

static int	ft_algorithm_1B(t_list **stack_A, t_list **stack_B, int half)
{
	t_node_data	*data_B0;
	t_node_data	*data_B1;
	int			moves;

	ft_load_data(*stack_B, &data_B0, &data_B1);
	moves = 0;
	if ((*stack_B)->next)
	{
		if (data_B0->ele < half && data_B0->ele < data_B1->ele)
			moves += ft_execute_operation("rb", &(*stack_A), &(*stack_B), 1);
		ft_load_data(*stack_B, &data_B0, &data_B1);
		if (data_B0->ele < data_B1->ele)
			moves += ft_execute_operation("sb", &(*stack_A), &(*stack_B), 1);
	}
	moves += ft_execute_operation("pa", &(*stack_A), &(*stack_B), 1);
	return (moves);
}
int	ft_algorithm_1(t_list **stack_A, t_list **stack_B)
{
	int	moves;
	int half;

	(void)ft_table_stacks;
	moves = 0;
	half = (ft_lstsize(*stack_A)-1) / 2;
	// half /= 2;
	while (*stack_A)
	{
		moves += ft_algorithm_1A(&(*stack_A), &(*stack_B), half);
	}
	// ft_table_stacks((*stack_A), (*stack_B));
	// getchar();
	while (*stack_B)
	{
		moves += ft_algorithm_1B(&(*stack_A), &(*stack_B), half);
	}
	// ft_table_stacks((*stack_A), (*stack_B));
	// getchar();
	return (moves);
}
