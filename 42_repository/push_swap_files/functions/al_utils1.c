/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:11:14 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/23 13:45:27 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	p(char *op, int ex)
{
	if (ex)
		ft_putstr(op);
	if (ex)
		ft_putstr("\n");
}

int	ft_execute_operation(char *op, t_list **stack_A, t_list **stack_B, int ex)
{
	p(op, ex);
	if (!ft_strncmp(op, "sa", 2))
		operation_sa(&(*stack_A));
	else if (!ft_strncmp(op, "sb", 2))
		operation_sb(&(*stack_B));
	else if (!ft_strncmp(op, "ss", 2))
		operation_ss(&(*stack_A), &(*stack_B));
	else if (!ft_strncmp(op, "pa", 2))
		operation_pa(&(*stack_A), &(*stack_B));
	else if (!ft_strncmp(op, "pb", 2))
		operation_pb(&(*stack_A), &(*stack_B));
	else if (!ft_strncmp(op, "rra", 3))
		operation_rra(&(*stack_A));
	else if (!ft_strncmp(op, "rrb", 3))
		operation_rrb(&(*stack_B));
	else if (!ft_strncmp(op, "rrr", 3))
		operation_rrr(&(*stack_A), &(*stack_B));
	else if (!ft_strncmp(op, "ra", 2))
		operation_ra(&(*stack_A));
	else if (!ft_strncmp(op, "rb", 2))
		operation_rb(&(*stack_B));
	else if (!ft_strncmp(op, "rr", 2))
		operation_rr(&(*stack_A), &(*stack_B));
	return (1);
}

t_node_data	*ft_get_higher_element(t_list *stack, int max_pos)
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
		if (data->ele > element->ele && data->pos < max_pos)
			element = data;
		i++;
		stack = stack->next;
	}
	return (element);
}

t_node_data	*ft_get_smallest_element(t_list *stack, int max_pos)
{
	int			i;
	int			size;
	t_node_data	*element;
	t_node_data	*data;

	i = 0;
	element = ft_get_higher_element(stack, max_pos);
	size = ft_lstsize(stack);
	while (i < size)
	{
		data = (stack)->content;
		if (data->ele < element->ele && data->pos < max_pos)
			element = data;
		i++;
		stack = stack->next;
	}
	return (element);
}

int	element_on_stack(int element, t_list *stack)
{
	t_node_data	*data;

	if (!stack)
		return (0);
	while (stack->next)
	{
		data = stack->content;
		if (data->ele == element)
			return (data->pos);
		stack = stack->next;
	}
	return (0);
}
