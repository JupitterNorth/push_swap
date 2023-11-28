/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   individual_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:27:52 by gneto-co          #+#    #+#             */
/*   Updated: 2023/11/28 11:53:06 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_files/push_swap.h"
#include <stdio.h>

/* //ft_stack_creation
int main()
{
	int array[] = {23, 42, 9, 5, 2};
	t_list		*stack;
	t_node_data	*data;
	
	stack = ft_stack_creation(array, 5);
	printf("--(%d)--", ft_lstsize(stack));

	for (size_t i = 0; i < 5; i++)
	{
		data = stack->content;
		printf("\n"
		"\nelemento: %d"
		"\nnumero: %d"
		"\nposicao: %d"
		"\n"
		, data->ele, data->nb, data->pos);
		stack = stack->next;
	}
	
	
} */
/* static void	ft_print_stack(t_list *stack, int size)
{
	int i;
	t_node_data	*data;
	
	i = 0;
	while(i < size)
	{
		data = stack->content;
		printf("\n"
		"\nelemento: %d"
		"\nnumero: %d"
		"\nposicao: %d"
		"\n"
		, data->ele, data->nb, data->pos);
		stack = stack->next;
		i++;
	}
} */

/* static void	ft_table_stack(t_list *stack, int size, char c)
{
	int i;
	t_node_data	*data[size];
	
	i = 0;
	while(i < size)
	{
		data[i] = stack->content;
		stack = stack->next;
		i++;
	}

	i = 0;
	printf(
		"\n┌─────┬─────┬─────┐"
		"\n│  %c  │ ele │ num │"
		,c
	);
	while (i < size)
	{
		printf(
			"\n├─────┼─────┼─────┤"
			"\n│ %3d │ %3d │ %3d │"
			,data[i]->pos
			,data[i]->ele
			,data[i]->nb
		);
		i++;
	}
	printf(
		"\n└─────┴─────┴─────┘"
	);
	
} */

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
	
}

//operations
int main()
{
	// criar stack A e B de exemplo
	int arrayA[] = {20, 10, 30};
	int arrayB[] = {40, 50, 60};
	t_list		*stack_A;
	t_list		*stack_B;
	stack_A = ft_stack_creation(arrayA, sizeof(arrayA) / sizeof(arrayA[0]));
	stack_B = ft_stack_creation(arrayB, sizeof(arrayB) / sizeof(arrayB[0]));

	// imprimir stack A e B
	ft_table_stacks(stack_A, stack_B);
	
	// operacao sa
	operation_sa(&stack_A);
	printf("\n----(ss)----\n");
	
	// imprimir stack A e B
	ft_table_stacks(stack_A, stack_B);
}
