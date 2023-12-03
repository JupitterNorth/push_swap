/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:14 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/03 13:42:45 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int ft_get_higher_element(t_list *stack)
{
	int	i;
	int element;
	int size;
	t_node_data	*data;

	i = 0;
	element = 0;
	size = ft_lstsize(stack);
	
	while (i < size)
	{
		data = (stack)->content;
		if (data->ele > element)
			element = data->ele;
		i++;
		stack = stack->next;
	}
	return element;
}

static int ft_get_smallest_element(t_list *stack)
{
	int	i;
	int element;
	int size;
	t_node_data	*data;

	i = 0;
	element = ft_get_higher_element(stack);
	size = ft_lstsize(stack);
	
	while (i < size)
	{
		data = (stack)->content;
		if (data->ele < element)
			element = data->ele;
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

int	ft_algorithm_2A(t_list **stack_A, t_list **stack_B)
{
	t_node_data	*data_A0;
	t_node_data	*data_A1;
	int			moves;
	int			higher_ele;

	ft_load_data(*stack_A, &data_A0, &data_A1);
	moves = 0;
	
	higher_ele = ft_get_smallest_element(*stack_A);
	//se houver pelo menos dois elementos
	if ((*stack_A)->next)
	{
		while (data_A0->ele != higher_ele)
		{
			al_execution("ra", &(*stack_A), &(*stack_B));
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
