/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:14:22 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/02 19:03:41 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	op_reverse_rotate(t_list **first_node)
{
	t_list	*second_last_node;
	t_list	*last_node;

	if (!(*first_node) || !(*first_node)->next)
		return ;
	last_node = ft_lstlast(*first_node);
	second_last_node = ft_lst_second_last(*first_node);
	last_node->next = (*first_node);
	second_last_node->next = NULL;
	(*first_node) = last_node;
	ft_organize_stack(&(*first_node));
}

void	operation_rra(t_list **stack_A)
{
	op_reverse_rotate(&(*stack_A));
}

void	operation_rrb(t_list **stack_B)
{
	op_reverse_rotate(&(*stack_B));
}

void	operation_rrr(t_list **stack_A, t_list **stack_B)
{
	op_reverse_rotate(&(*stack_A));
	op_reverse_rotate(&(*stack_B));
}
