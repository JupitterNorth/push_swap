/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:30:08 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/02 18:56:36 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_in_order(t_list *stack)
{
	t_node_data	*data;

	if (!stack)
		return (0);
	while (stack)
	{
		data = stack->content;
		if (data->ele != data->pos)
			return (0);
		stack = stack->next;
	}
	return (1);
}
