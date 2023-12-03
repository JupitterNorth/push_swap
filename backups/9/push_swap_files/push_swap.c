/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:11:03 by gneto-co          #+#    #+#             */
/*   Updated: 2023/11/30 16:09:49 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


int	ft_push_swap(int *nb_list, int size)
{
	t_list *stack_A;
	t_list *stack_B;
	int moves;
	// create stacks A and B
	stack_A = ft_stack_creation(nb_list, size);
	stack_B = ft_stack_creation(NULL, 0);

    // show original stacks
    ft_table_stacks(stack_A, stack_B);

    ft_putstr("\n\n");
    
	// execute algorithm
	moves = ft_sort_stack(&stack_A, &stack_B);
    // moves = 0;

    ft_putstr("\n\n");

    // show final stacks
    ft_table_stacks(stack_A, stack_B);

    // free stacks
    ft_lstclear(&stack_A, free);
    ft_lstclear(&stack_B, free);
    
    
	return (moves);
}