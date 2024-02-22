/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:51:36 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/22 15:58:06 by gneto-co         ###   ########.fr       */
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
