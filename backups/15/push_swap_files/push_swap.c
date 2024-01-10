/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:11:03 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/10 11:53:55 by gneto-co         ###   ########.fr       */
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

// static void	ft_table_stacks(t_list *stack_a, t_list *stack_b)
// {
// 	int			i;
// 	int			size_a;
// 	int			size_B;
// 	size_a = ft_lstsize(stack_a);
// 	size_B = ft_lstsize(stack_b);
// 	t_node_data	*data_A[size_a];
// 	t_node_data	*data_b[size_B];

// 	i = 0;
// 	while (i < size_a)
// 	{
// 		data_A[i] = stack_a->content;
// 		stack_a = stack_a->next;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < size_B)
// 	{
// 		data_b[i] = stack_b->content;
// 		stack_b = stack_b->next;
// 		i++;
// 	}
// 	i = 0;
// 	printf("\n┌─────┬─────┬─────┐┌─────┬─────┬─────┐"
// 			"\n│  A  │ ele │ num ││  B  │ ele │ num │");
// 	while (i < size_a || i < size_B)
// 	{
// 		printf("\n├─────┼─────┼─────┤├─────┼─────┼─────┤\n");
// 		if (i < size_a)
// 			printf("│ %3d │ %3d │ %3d │", data_A[i]->pos, data_A[i]->ele,
// 				data_A[i]->nb);
// 		else
// 			printf("│     │     │     │");
// 		if (i < size_B)
// 			printf("│ %3d │ %3d │ %3d │", data_b[i]->pos, data_b[i]->ele,
// 				data_b[i]->nb);
// 		else
// 			printf("│     │     │     │");
// 		i++;
// 	}
// 	printf("\n└─────┴─────┴─────┘└─────┴─────┴─────┘\n");
// 	fflush(stdout);
// }

// int	ft_push_swap(int *nb_list, int size)
// {
// 	t_list	*stack_a;
// 	t_list	*stack_b;
// 	int		moves;
// 	char	okko[] = "ko";

// // create stacks
// 	moves = 0;
// 	stack_a = ft_stack_creation(nb_list, size);
// 	stack_b = ft_stack_creation(NULL, 0);
// // show original stack
// 	printf("\n---------- Original Stack ----------");
// 	ft_table_stacks(stack_a, stack_b);
// // sort stack if is not in correct order
// 	if (!stack_in_order(stack_a))
// 		moves = ft_sort_stack(&stack_a, &stack_b);
// // show final result
// 	if (stack_in_order(stack_a) && !stack_b)
// 	{
// 		okko[0] = 'o';
// 		okko[1] = 'k';
// 	}

// 	printf(
// 		"\n┌─────────┬──────┐"
// 		"\n│  moves  │ sort │"
// 		"\n├─────────┼──────┤"
// 		"\n│ %6d  │  %s  │"
// 		"\n└─────────┴──────┘\n"
// 		,moves, okko
// 		);
// // clear list and return
// 	ft_lstclear(&stack_a, free);
// 	ft_lstclear(&stack_b, free);
// 	return (moves);
// }