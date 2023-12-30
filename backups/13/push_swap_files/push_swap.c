/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:11:03 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/29 23:32:20 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_swap(int *nb_list, int size)
{
	t_list *stack_A;
	t_list *stack_B;
	int moves;
	
	moves = 0;
// create stacks A and B
	stack_A = ft_stack_creation(nb_list, size);
	stack_B = ft_stack_creation(NULL, 0);

// show original stacks
	ft_putstr("\nOriginal Stack");
	ft_table_stacks(stack_A, stack_B);


// execute algorithm if stack is not in order
	if (!stack_in_order(stack_A))
		moves = ft_sort_stack(&stack_A, &stack_B);
	
// show final stack and the result
	// ft_table_stacks(stack_A, stack_B);
	ft_putstr("\nFinal Stack -");
	if (stack_in_order(stack_A) && !stack_B)
		ft_putstr("\033[32m Correct Order\n\033[0m");
	else
		ft_putstr("\033[31m Wrong Order\n\033[0m");
	printf("\n\nMoves: %d\n\n", moves);


// save results to a file
	// FILE *file;
	// file = fopen("testes.txt", "a");
	// if (file)
	// {
	// 	char *text;
	// 	text = ft_itoa(ft_lstsize(stack_A));
	// 	fprintf(file, "\nStack size: %s", text);
	// 	free(text);
	// 	text = ft_itoa(moves);
	// 	fprintf(file, "\nMovements:\t\t\t\t\t%s", text);
	// 	free(text);
	// 	fprintf(file, "\nResult: ");
	// 	if (stack_in_order(stack_A) && !stack_B)
	// 		fprintf(file, "Correct Order\n");
	// 	else
	// 		fprintf(file, "WRONG ORDER\n");
	// }
	// fclose(file);


// free stacks
	ft_lstclear(&stack_A, free);
	ft_lstclear(&stack_B, free);


	return (moves);
}
