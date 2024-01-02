/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:14 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/02 17:57:32 by gneto-co         ###   ########.fr       */
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

static void	ft_algorithm_2b(t_list *stack_a, t_variables v,
		t_node_data **data_aa)
{
	if (v.modo == 1)
		*data_aa = ft_get_smallest_element(stack_a, v.size);
	else if (v.modo == 2)
		*data_aa = ft_get_higher_element(stack_a, v.size);
}

static int	ft_algorithm_2a(t_list **stack_a, t_list **stack_b, t_variables v)
{
	t_node_data	*data_a0;
	t_node_data	*data_a1;
	t_node_data	*data_aa;
	int			moves;

	ft_algorithm_2b(*stack_a, v, &data_aa);
	ft_load_data(*stack_a, &data_a0, &data_a1);
	moves = 0;
	if ((*stack_a)->next)
	{
		while (data_a0 != data_aa)
		{
			ft_algorithm_2b(*stack_a, v, &data_aa);
			if (data_aa->pos < v.half)
				moves += ft_execute_operation("ra", &(*stack_a), &(*stack_b),
						v.exe);
			else
				moves += ft_execute_operation("rra", &(*stack_a), &(*stack_b),
						v.exe);
			ft_load_data(*stack_a, &data_a0, &data_a1);
		}
	}
	moves += ft_execute_operation("pb", &(*stack_a), &(*stack_b), v.exe);
	return (moves);
}

int	ft_algorithm_2(t_list **stack_a, t_list **stack_b, t_variables v)
{
	int	moves;
	int	i;

	moves = 0;
	i = 0;
	while (i < v.size)
	{
		v.half = (ft_lstsize(*stack_a)) / 2;
		moves += ft_algorithm_2a(&(*stack_a), &(*stack_b), v);
		i++;
	}
	if (v.modo == 1)
	{
		while (i)
		{
			moves += ft_execute_operation("pa", &(*stack_a), &(*stack_b),
					v.exe);
			i--;
		}
	}
	return (moves);
}
