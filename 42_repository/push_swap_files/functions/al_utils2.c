/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:51:36 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/23 12:58:16 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node_data	*ft_get_first_element_on_range(t_list *stack, int r_begin,
		int r_end)
{
	int			i;
	int			size;
	t_node_data	*element;
	t_node_data	*data;

	i = 0;
	element = stack->content;
	size = ft_lstsize(stack);
	while (i < size)
	{
		data = (stack)->content;
		if (data->ele >= r_begin && data->ele <= r_end)
		{
			element = data;
			break ;
		}
		i++;
		stack = stack->next;
	}
	return (element);
}

t_node_data	*ft_get_last_element_on_range(t_list *stack, int r_begin, int r_end)
{
	int			i;
	int			size;
	t_node_data	*element;
	t_node_data	*data;

	i = 0;
	element = stack->content;
	size = ft_lstsize(stack);
	while (i < size)
	{
		data = (stack)->content;
		if (data->ele >= r_begin && data->ele <= r_end)
			element = data;
		i++;
		stack = stack->next;
	}
	return (element);
}

static void	ft_load_data(t_list *stack, t_node_data **data_0)
{
	if (stack)
		(*data_0) = stack->content;
}

void	change_to_stack_b(t_node_data *member_position, t_list **stack_a,
		t_list **stack_b)
{
	t_node_data	*data_a0;

	ft_load_data(*stack_a, &data_a0);
	while (data_a0 != member_position)
	{
		if (member_position->pos < (ft_lstsize(*stack_a)) / 2)
			ft_execute_operation("ra", &(*stack_a), &(*stack_b), 1);
		else
			ft_execute_operation("rra", &(*stack_a), &(*stack_b), 1);
		ft_load_data(*stack_a, &data_a0);
	}
	ft_execute_operation("pb", &(*stack_a), &(*stack_b), 1);
}

void	change_to_stack_a(t_node_data *member_position, t_list **stack_a,
		t_list **stack_b)
{
	t_node_data	*data_b0;

	ft_load_data(*stack_b, &data_b0);
	while (data_b0 != member_position)
	{
		if (member_position->pos < (ft_lstsize(*stack_b)) / 2)
			ft_execute_operation("rb", &(*stack_a), &(*stack_b), 1);
		else
			ft_execute_operation("rrb", &(*stack_a), &(*stack_b), 1);
		ft_load_data(*stack_b, &data_b0);
	}
	ft_execute_operation("pa", &(*stack_a), &(*stack_b), 1);
}
