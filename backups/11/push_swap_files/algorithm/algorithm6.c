/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:15:02 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/27 16:42:02 by gneto-co         ###   ########.fr       */
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

static int	ft_get_faster_chunk(t_list *stack)
{
	int			number;
	int			chunks_number;
	t_node_data	*data;
	int 		*counter;
	
	if (ft_lstsize(stack) < CHUNK_SIZE)
		return 0;
	chunks_number = ft_lstsize(stack) / CHUNK_SIZE;
	counter = ft_calloc(chunks_number, sizeof(int));
	if (!counter)
		return -1;
	
	while (stack)
	{
		data = stack->content;
		number = data->ele/CHUNK_SIZE;
		counter[number]++; // segmentation fault (core dumped)
		if (counter[number] == CHUNK_SIZE)
			break ;
		stack = stack->next;
	}

	free(counter);
	return number;
}

static int	ft_push_chunks(t_list **stack_A, t_list **stack_B)
{
	t_node_data	*data_A0;
	int	chunk_number;
	int i;
	int moves;

	moves = 0;
	while (ft_lstsize(*stack_A) > CHUNK_SIZE)
	{
		chunk_number = ft_get_faster_chunk(*stack_A);
		i = 0;
		while (i < CHUNK_SIZE)
		{
			data_A0 = (*stack_A)->content;
			
			// ft_table_stacks(*stack_A, *stack_B);
			// printf(
			// 	"\nif (%d >= %d < %d)"
			// 	"\nchunk_number: %d"
			// 	"\nindex: %d",
			// 	(chunk_number * CHUNK_SIZE), (data_A0->ele), ((chunk_number+1) * CHUNK_SIZE), chunk_number, i);
			// getchar();
			
			if(data_A0->ele >= chunk_number * CHUNK_SIZE && data_A0->ele < (chunk_number+1) * CHUNK_SIZE)
			{
				moves += ft_execute_operation("pb", &(*stack_A), &(*stack_B));
				i++;
			}
			moves += ft_execute_operation("ra", &(*stack_A), &(*stack_B));

		}
	}
	return moves;
}

// algorithm 6
// version: 1.0
// sort a stacks with only 4 or 5 elements
int	ft_algorithm_6(t_list **stack_A, t_list **stack_B)
{
	// t_node_data	*data_A0;
	// t_node_data	*data_A1;
	// t_node_data	*data_B0;
	// t_node_data	*data_B1;
	int			moves;
	// int			size;

	// size = ft_lstsize(*stack_A);
	// moves = 0;
	// ft_load_data(*stack_A, &data_A0, &data_A1);
	// moves += ft_execute_operation("ra", &(*stack_A), &(*stack_B));
	// return (moves);

	(void)stack_B;
	(void)ft_load_data;
	(void)ft_push_chunks;

	moves = ft_push_chunks(&(*stack_A), &(*stack_B));
	while (*stack_A)
		moves += ft_execute_operation("pb", &(*stack_A), &(*stack_B));
	
	moves += ft_algorithm_2(&(*stack_A), &(*stack_B), ft_lstsize(*stack_A), 1);
	moves += ft_algorithm_2(&(*stack_B), &(*stack_A), ft_lstsize(*stack_B), 2);

	return moves;
}
