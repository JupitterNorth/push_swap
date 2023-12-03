/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:14 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/03 16:14:49 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node_data *ft_get_higher_element(t_list *stack)
{
	int	i;
	int size;
	t_node_data *element;
	t_node_data	*data;

	i = 0;
	element = stack->content;
	size = ft_lstsize(stack);
	while (i < size)
	{
		data = (stack)->content;
	// ft_putnbr();
		if (data->ele > element->ele)
			element = data;
		i++;
		stack = stack->next;
	}
	return element;
}

static t_node_data *ft_get_smallest_element(t_list *stack)
{
	int	i;
	int size;
	t_node_data *element;
	t_node_data	*data;

	i = 0;
	element = ft_get_higher_element(stack);
	size = ft_lstsize(stack);
	
	while (i < size)
	{
		data = (stack)->content;
		if (data->ele < element->ele)
			element = data;
		i++;
		stack = stack->next;
	}
	return element;
}

static void	ft_load_data(t_list *stack, t_node_data **data_0,
		t_node_data **data_1)
{
	if (stack)
		(*data_0) = stack->content;
	if (stack->next)
		(*data_1) = stack->next->content;
}

// algorithm 2
// version 1.0

int	ft_algorithm_2A(t_list **stack_A, t_list **stack_B, int half)
{
	t_node_data	*data_A0;
	t_node_data	*data_A1;
	t_node_data	*data_A_min;
	int			moves;

	ft_load_data(*stack_A, &data_A0, &data_A1);
	moves = 0;
	
	data_A_min = ft_get_smallest_element(*stack_A);
	//se houver pelo menos dois elementos
	if ((*stack_A)->next)
	{
		while (data_A0->ele != data_A_min->ele)
		{
			data_A_min = ft_get_smallest_element(*stack_A);
			ft_putstr("\nexe:");
			if (data_A_min->pos < half)
				al_execution("ra", &(*stack_A), &(*stack_B));
			else
				al_execution("rra", &(*stack_A), &(*stack_B));
			moves++;
			ft_load_data(*stack_A, &data_A0, &data_A1);
		}
	}
	al_execution("pb", &(*stack_A), &(*stack_B));
	moves++;
	return (moves);
}
int	ft_algorithm_2B(t_list **stack_A, t_list **stack_B)
{
	int			moves;

	moves = 0;
	al_execution("pa", &(*stack_A), &(*stack_B));
	moves++;
	return (moves);
}
