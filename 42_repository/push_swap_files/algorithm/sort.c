/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:10:01 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/22 18:00:08 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		return (ft_execute_operation("sa", &(*stack_a), &(*stack_b), 1));
	else if (ft_lstsize(*stack_a) == 3)
		return (ft_algorithm_4(&(*stack_a), &(*stack_b)));
	else if (ft_lstsize(*stack_a) <= 5)
		return (ft_algorithm_5(&(*stack_a), &(*stack_b)));
	else
		return (ft_algorithm_1(&(*stack_a), &(*stack_b)));
	return (0);
}
