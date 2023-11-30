/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:14 by gneto-co          #+#    #+#             */
/*   Updated: 2023/11/30 15:02:47 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
0 - execute every operations and return number of moves

1 - sa
2 - sb
3 - ss

4 - pa
5 - pb

6 - ra
7 - rb
8 - rr

9 - rra
10 - rrb
11 - rrr
*/

int	ft_algorithm_1A(t_list **stack_A, t_list **stack_B)
{
	t_node_data	*data_A0;
	t_node_data	*data_A1;
	int			moves;

	if(*stack_A)
		data_A0 = (*stack_A)->content;
	if((*stack_A)->next)
		data_A1 = (*stack_A)->next->content;
	moves = 0;
	if (data_A0->ele > data_A1->ele)
	{
		al_execution("sa", &(*stack_A), &(*stack_B));
		moves++;
	}
	al_execution("pb", &(*stack_A), &(*stack_B));
	moves++;
	return (moves);
}

int	ft_algorithm_1B(t_list **stack_A, t_list **stack_B)
{
	t_node_data	*data_B0;
	t_node_data	*data_B1;
	int			moves;

	if(*stack_B)
		data_B0 = (*stack_B)->content;
	if((*stack_B)->next)
		data_B1 = (*stack_B)->next->content;
	moves = 0;
	if (data_B0->ele < data_B1->ele)
	{
		al_execution("sb", &(*stack_A), &(*stack_B));
		moves++;
	}
	al_execution("pa", &(*stack_A), &(*stack_B));
	moves++;
	return (moves);
}
