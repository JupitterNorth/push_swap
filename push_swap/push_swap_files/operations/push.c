/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:37:34 by gneto-co          #+#    #+#             */
/*   Updated: 2023/11/28 18:16:50 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	op_push(t_list **dest, t_list **src)
{
	t_list	*temp;

	if (!(*src))
		return ;
    temp = (*src)->next;
	(*src)->next = (*dest);
	(*dest) = (*src);
    (*src) = temp;
}

void	operation_pa(t_list **stack_A, t_list **stack_B)
{
	op_push(&(*stack_A), &(*stack_B));
}

void	operation_pb(t_list **stack_A, t_list **stack_B)
{
	op_push(&(*stack_B), &(*stack_A));
}