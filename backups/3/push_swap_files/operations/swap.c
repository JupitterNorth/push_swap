/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:24:54 by gneto-co          #+#    #+#             */
/*   Updated: 2023/11/28 10:45:20 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	op_swap(t_list **node0)
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

void	operation_sa(t_list **stack_A)
{
	op_swap(&(*stack_A));
}

void	operation_sb(t_list **stack_B)
{
	op_swap(&(*stack_B));
}

void	operation_ss(t_list **stack_A, t_list **stack_B)
{
	op_swap(&(*stack_A));
	op_swap(&(*stack_B));
}