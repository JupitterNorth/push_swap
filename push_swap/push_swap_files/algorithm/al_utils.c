/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:11:14 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/03 16:13:59 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	al_execution(char *op, t_list **stack_A, t_list **stack_B)
{
	ft_putstr(op);
	ft_putstr("\n");
	if (!ft_strncmp(op,"sa", 2))
		operation_sa(&(*stack_A));
	else if (!ft_strncmp(op,"sb", 2))
		operation_sb(&(*stack_B));
	else if (!ft_strncmp(op,"ss", 2))
		operation_ss(&(*stack_A), &(*stack_B));
	else if (!ft_strncmp(op,"pa", 2))
		operation_pa(&(*stack_A), &(*stack_B));
	else if (!ft_strncmp(op,"pb", 2))
		operation_pb(&(*stack_A), &(*stack_B));
	else if (!ft_strncmp(op,"rra", 3))
		operation_rra(&(*stack_A));
	else if (!ft_strncmp(op,"rrb", 3))
		operation_rrb(&(*stack_B));
	else if (!ft_strncmp(op,"rrr", 3))
		operation_rrr(&(*stack_A), &(*stack_B));
	else if (!ft_strncmp(op,"ra", 2))
		operation_ra(&(*stack_A));
	else if (!ft_strncmp(op,"rb", 2))
		operation_rb(&(*stack_B));
	else if (!ft_strncmp(op,"rr", 2))
		operation_rr(&(*stack_A), &(*stack_B));
}
