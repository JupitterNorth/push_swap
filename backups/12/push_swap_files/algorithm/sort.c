/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:10:01 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/28 12:31:12 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sort_stack(t_list **stack_A, t_list **stack_B)
{
	(void)ft_table_stacks;
	if (ft_lstsize(*stack_A) == 2)
		return (ft_execute_operation("sa", &(*stack_A), &(*stack_B)));
	else if (ft_lstsize(*stack_A) == 3)
		return (ft_algorithm_4(&(*stack_A), &(*stack_B)));
	else if (ft_lstsize(*stack_A) <= 5)
		return (ft_algorithm_5(&(*stack_A), &(*stack_B)));
	else if (ft_lstsize(*stack_A) <= 50)
		return(ft_algorithm_2(&(*stack_A), &(*stack_B), ft_lstsize(*stack_A), 1));
	else if (ft_lstsize(*stack_A) <= 100)
		return (ft_algorithm_6(&(*stack_A), &(*stack_B), 25));
	else
		return (ft_algorithm_6(&(*stack_A), &(*stack_B), 50));
	
	return (0);
}
