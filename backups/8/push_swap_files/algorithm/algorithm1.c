/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:14 by gneto-co          #+#    #+#             */
/*   Updated: 2023/11/30 18:06:19 by gneto-co         ###   ########.fr       */
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

// 3.0
int	ft_algorithm_1A(t_list **stack_A, t_list **stack_B, int half)
{
	t_node_data	*data_A0;
	t_node_data	*data_A1;
	int			moves;

	ft_load_data(*stack_A, &data_A0, &data_A1);
	moves = 0;
	if ((*stack_A)->next)
	{
		if (data_A0->ele > half && data_A0->ele > data_A1->ele)
		{
			al_execution("ra", &(*stack_A), &(*stack_B));
			moves++;
		}
		ft_load_data(*stack_A, &data_A0, &data_A1);
		if (data_A0->ele > data_A1->ele)
		{
			al_execution("sa", &(*stack_A), &(*stack_B));
			moves++;
		}
	}
	al_execution("pb", &(*stack_A), &(*stack_B));
	moves++;
	return (moves);
}

int	ft_algorithm_1B(t_list **stack_A, t_list **stack_B, int half)
{
	t_node_data	*data_B0;
	t_node_data	*data_B1;
	int			moves;

	ft_load_data(*stack_B, &data_B0, &data_B1);
	moves = 0;
	if ((*stack_B)->next)
	{
		if (data_B0->ele < half && data_B0->ele < data_B1->ele)
		{
			al_execution("rb", &(*stack_A), &(*stack_B));
			moves++;
		}
		ft_load_data(*stack_B, &data_B0, &data_B1);
		if (data_B0->ele < data_B1->ele)
		{
			al_execution("sb", &(*stack_A), &(*stack_B));
			moves++;
		}
	}
	al_execution("pa", &(*stack_A), &(*stack_B));
	moves++;
	return (moves);
}
