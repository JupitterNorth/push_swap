/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:14 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/10 11:54:18 by gneto-co         ###   ########.fr       */
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

static int	ft_algorithm_2_mod1(t_list **stack_a, t_list **stack_b,
		t_variables v)
{
	t_node_data	*data_a0;
	t_node_data	*data_a1;
	t_node_data	*data_aa;
	int			moves;

	v.half = (ft_lstsize(*stack_a)) / 2;
	data_aa = ft_get_smallest_element(*stack_a, v.size);
	ft_load_data(*stack_a, &data_a0, &data_a1);
	moves = 0;
	if ((*stack_a)->next)
	{
		while (data_a0 != data_aa)
		{
			data_aa = ft_get_smallest_element(*stack_a, v.size);
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

static int	ft_algorithm_2_mod2(t_list **stack_a, t_list **stack_b,
		t_variables v)
{
	t_node_data	*data_b0;
	t_node_data	*data_b1;
	t_node_data	*data_bb;
	int			moves;

	v.half = (ft_lstsize(*stack_b)) / 2;
	data_bb = ft_get_higher_element(*stack_b, v.size);
	ft_load_data(*stack_b, &data_b0, &data_b1);
	moves = 0;
	if ((*stack_b)->next)
	{
		while (data_b0 != data_bb)
		{
			data_bb = ft_get_higher_element(*stack_b, v.size);
			if (data_bb->pos < v.half)
				moves += ft_execute_operation("rb", &(*stack_a), &(*stack_b),
						v.exe);
			else
				moves += ft_execute_operation("rrb", &(*stack_a), &(*stack_b),
						v.exe);
			ft_load_data(*stack_b, &data_b0, &data_b1);
		}
	}
	moves += ft_execute_operation("pa", &(*stack_a), &(*stack_b), v.exe);
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
		if (v.modo == 1)
			moves += ft_algorithm_2_mod1(&(*stack_a), &(*stack_b), v);
		else
			moves += ft_algorithm_2_mod2(&(*stack_a), &(*stack_b), v);
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
