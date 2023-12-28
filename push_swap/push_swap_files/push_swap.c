/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:11:03 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/28 16:51:55 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_swap(int *nb_list, int size)
{
	t_list *stack_A;
	t_list *stack_A_dup;
	t_list *stack_B;
	int moves;
	
	moves = 0;
// create stacks A and B
	stack_A = ft_stack_creation(nb_list, size);
	stack_B = ft_stack_creation(NULL, 0);

// dup stack A
	stack_A_dup = ft_lstdup(stack_A, free);
	

// show original stacks
	ft_putstr("\nOriginal Stack");
	ft_table_stacks(stack_A, stack_B);
	ft_putstr("\nDup Stack");
	ft_table_stacks(stack_A_dup, stack_B);
	getchar();

// execute algorithm if stack is not in order
	// if (!stack_in_order(stack_A))
	// 	moves = ft_sort_stack(&stack_A, &stack_B);

	// (void)ft_table_stacks;
	
// show final stack and the result
	// ft_table_stacks(stack_A, stack_B);
	// ft_putstr("\nFinal Stack -");
	// if (stack_in_order(stack_A) && !stack_B)
	// 	ft_putstr("\033[32m Correct Order\n\033[0m");
	// else
	// 	ft_putstr("\033[31m Wrong Order\n\033[0m");
	// printf("\n\nMoves: %d\n\n", moves);

// save results to a file
	// FILE *arquivo;
	// arquivo = fopen("testes.txt", "a");
	// if (arquivo)
	// {
	// 	char *text;
	// 	text = ft_itoa(ft_lstsize(stack_A));
	// 	fprintf(arquivo, "\nStack size: %s", text);
	// 	free(text);
	// 	text = ft_itoa(moves);
	// 	fprintf(arquivo, "\nMovements:\t\t\t\t\t%s", text);
	// 	free(text);
	// 	fprintf(arquivo, "\nResult: ");
	// 	if (stack_in_order(stack_A) && !stack_B)
	// 		fprintf(arquivo, "Correct Order\n");
	// 	else
	// 		fprintf(arquivo, "WRONG ORDER\n");
	// }
	// fclose(arquivo);

// free stacks
	ft_lstclear(&stack_A, free);
	ft_lstclear(&stack_A_dup, free);
	ft_lstclear(&stack_B, free);

	return (moves);
}
