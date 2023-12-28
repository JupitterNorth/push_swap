/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:15:02 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/28 16:21:50 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_load_data(t_list *stack, t_node_data **data_0,
		t_node_data **data_1)
{
	if (stack)
		(*data_0) = stack->content;
	if (stack->next)
		(*data_1) = stack->next->content;
}

static int	ft_get_faster_chunk(t_list *stack, int chunk_size)
{
	int			number;
	int			chunks_number;
	t_node_data	*data;
	int 		*counter;
	
	if (ft_lstsize(stack) < chunk_size)
		return 0;
	chunks_number = ft_lstsize(stack) / chunk_size;
	counter = ft_calloc(chunks_number, sizeof(int));
	if (!counter)
		return -1;
	
	while (stack)
	{
		data = stack->content;
		number = data->ele/chunk_size;
		counter[number]++; // segmentation fault (core dumped)
		if (counter[number] == chunk_size)
			break ;
		stack = stack->next;
	}

	free(counter);
	return number;
}

static int	ft_push_chunks(t_list **stack_A, t_list **stack_B, int chunk_size, int exe)
{
	t_node_data	*data_A0;
	int	chunk_number;
	int i;
	int moves;

	moves = 0;
	while (ft_lstsize(*stack_A) > chunk_size)
	{
		chunk_number = ft_get_faster_chunk(*stack_A, chunk_size);
		i = 0;
		while (i < chunk_size)
		{
			data_A0 = (*stack_A)->content;
			
			// ft_table_stacks(*stack_A, *stack_B);
			// printf(
			// 	"\nif (%d >= %d < %d)"
			// 	"\nchunk_number: %d"
			// 	"\nindex: %d",
			// 	(chunk_number * chunk_size), (data_A0->ele), ((chunk_number+1) * chunk_size), chunk_number, i);
			// getchar();
			
			if(data_A0->ele >= chunk_number * chunk_size && data_A0->ele < (chunk_number+1) * chunk_size)
			{
				moves += ft_execute_operation("pb", &(*stack_A), &(*stack_B), exe);
				i++;
			}
			moves += ft_execute_operation("ra", &(*stack_A), &(*stack_B), exe);

		}
	}
	return moves;
}

// algorithm 6
// version: 1.0
// sort a stacks with lots of elements
int	ft_algorithm_6(t_list **stack_A, t_list **stack_B, int chunk_size, int exe)
{
	int			moves;

	(void)stack_B;
	(void)ft_load_data;
	(void)ft_push_chunks;

	moves = ft_push_chunks(&(*stack_A), &(*stack_B), chunk_size, exe);
	while (*stack_A)
		moves += ft_execute_operation("pb", &(*stack_A), &(*stack_B), exe);
	
	moves += ft_algorithm_2(&(*stack_B), &(*stack_A), ft_lstsize(*stack_B), 2, exe);

	return moves;
}
