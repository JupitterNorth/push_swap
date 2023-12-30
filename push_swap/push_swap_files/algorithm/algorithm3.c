/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:43:20 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/29 23:07:29 by gneto-co         ###   ########.fr       */
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

int	ft_algorithm_3(t_list **stack_A, t_list **stack_B, int exe)
{
	t_node_data *data_A0;
	t_node_data *data_A1;
	t_node_data *data_B0;
	t_node_data *data_B1;
	t_node_data *limit_A;
	t_node_data *limit_B;
	int moves;
	int size;
	int i;

	ft_load_data(*stack_A, &data_A0, &data_A1);
	moves = 0;
	i = 0;
	size = ft_lstsize(*stack_A);

	while (i++ < size / 2)
		moves += ft_execute_operation("pb", &(*stack_A), &(*stack_B), exe);

	i = 0;

	limit_A = ft_get_higher_element(*stack_A, size);
	limit_B = ft_get_smallest_element(*stack_B, size);
	while (i++ < size)
	{
		ft_load_data(*stack_A, &data_A0, &data_A1);
		ft_load_data(*stack_B, &data_B0, &data_B1);
		if (data_A0 == limit_A && data_B0 == limit_B)
			break ;
		if (data_A0->ele > data_A1->ele)
			moves += ft_execute_operation("sa", &(*stack_A), &(*stack_B), exe);
		if (data_B0->ele < data_B1->ele)
			moves += ft_execute_operation("sb", &(*stack_A), &(*stack_B), exe);
		moves += ft_execute_operation("rr", &(*stack_A), &(*stack_B), exe);
	}

	while (*stack_B)
		moves += ft_execute_operation("pa", &(*stack_A), &(*stack_B), exe);
	return (moves);
}
