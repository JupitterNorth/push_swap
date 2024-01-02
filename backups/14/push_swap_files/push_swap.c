/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:11:03 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/02 19:42:18 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_swap(int *nb_list, int size)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		moves;

	moves = 0;
	stack_a = ft_stack_creation(nb_list, size);
	stack_b = ft_stack_creation(NULL, 0);
	if (!stack_in_order(stack_a))
		moves = ft_sort_stack(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (moves);
}
