/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:10:01 by gneto-co          #+#    #+#             */
/*   Updated: 2023/11/30 16:23:19 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_table_stacks(t_list *stack_A, t_list *stack_B)
{
	int i;
	int size_A = ft_lstsize(stack_A);
	int size_B = ft_lstsize(stack_B);
	t_node_data	*data_A[size_A];
	t_node_data	*data_B[size_B];
	
	i = 0;
	while(i < size_A)
	{
		data_A[i] = stack_A->content;
		stack_A = stack_A->next;
		i++;
	}
	i = 0;
	while(i < size_B)
	{
		data_B[i] = stack_B->content;
		stack_B = stack_B->next;
		i++;
	}

	i = 0;
	printf(
		"\n┌─────┬─────┬─────┐┌─────┬─────┬─────┐"
		"\n│  A  │ ele │ num ││  B  │ ele │ num │"
	);
	while (i < size_A || i < size_B)
	{
		printf(
			"\n├─────┼─────┼─────┤├─────┼─────┼─────┤\n"
		);
		if (i < size_A)
			printf("│ %3d │ %3d │ %3d │", data_A[i]->pos, data_A[i]->ele, data_A[i]->nb);
		else
			printf("│     │     │     │");
		if (i < size_B)
			printf("│ %3d │ %3d │ %3d │", data_B[i]->pos, data_B[i]->ele, data_B[i]->nb);
		else
			printf("│     │     │     │");
		i++;
	}
	printf(
		"\n└─────┴─────┴─────┘└─────┴─────┴─────┘"
	);
	fflush(stdout);
}

int	ft_sort_stack(t_list **stack_A, t_list **stack_B)
{
	int	moves;
	// int half;
	
    (void)ft_table_stacks;
	moves = 0;
	// half = ft_lstsize(*stack_A)-1;
	while (!stack_in_order(*stack_A))
	{
		// half /= 2;
        while (*stack_A)
        {
    		moves += ft_algorithm_1A(&(*stack_A), &(*stack_B));
        }
        // ft_table_stacks((*stack_A), (*stack_B));
        // getchar();
        while (*stack_B)
        {
		    moves += ft_algorithm_1B(&(*stack_A), &(*stack_B));
        }
        // ft_table_stacks((*stack_A), (*stack_B));
        // getchar();
	}
    return moves;
}