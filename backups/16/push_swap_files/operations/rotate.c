/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:14:22 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/02 19:03:12 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	op_rotate(t_list **first_node)
{
	t_list	*second_node;
	t_list	*last_node;

	if (!(*first_node) || !(*first_node)->next)
		return ;
	second_node = (*first_node)->next;
	last_node = ft_lstlast(*first_node);
	last_node->next = (*first_node);
	(*first_node)->next = NULL;
	(*first_node) = second_node;
	ft_organize_stack(&(*first_node));
}

void	operation_ra(t_list **stack_A)
{
	op_rotate(&(*stack_A));
}

void	operation_rb(t_list **stack_B)
{
	op_rotate(&(*stack_B));
}

void	operation_rr(t_list **stack_A, t_list **stack_B)
{
	op_rotate(&(*stack_A));
	op_rotate(&(*stack_B));
}
