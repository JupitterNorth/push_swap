/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:14:22 by gneto-co          #+#    #+#             */
/*   Updated: 2023/11/28 20:16:33 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

static void	op_rotate(t_list **node0)
{
	t_list		*node1;
	t_node_data	*data0;
	t_node_data	*data1;
	
	if (!(*node0) || !((*node0)->next))
		return ;
	node1 = (*node0)->next;
	data0 = (*node0)->content;
	data1 = node1->content;
	data0->pos = 1;
	data1->pos = 0;
	(*node0)->next = node1->next;
	node1->next = (*node0);
	(*node0) = node1;
}

void	operation_ra(t_list **stack_A)
{
	op_swap(&(*stack_A));
}

void	operation_rb(t_list **stack_B)
{
	op_swap(&(*stack_B));
}

void	operation_rr    (t_list **stack_A, t_list **stack_B)
{
	op_swap(&(*stack_A));
	op_swap(&(*stack_B));
}