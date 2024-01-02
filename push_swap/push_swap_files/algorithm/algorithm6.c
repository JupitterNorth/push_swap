/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:15:02 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/02 18:27:46 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_get_faster_chunk(t_list *stack, int chunk_size)
{
	int			number;
	int			chunks_number;
	t_node_data	*data;
	int			*counter;

	if (ft_lstsize(stack) < chunk_size)
		return (0);
	chunks_number = ft_lstsize(stack) / chunk_size;
	counter = ft_calloc(chunks_number, sizeof(int));
	if (!counter)
		return (-1);
	while (stack)
	{
		data = stack->content;
		number = data->ele / chunk_size;
		counter[number]++;
		if (counter[number] == chunk_size)
			break ;
		stack = stack->next;
	}
	free(counter);
	return (number);
}

static int	ft_push_chunks(t_list **stack_a, t_list **stack_b, t_variables v)
{
	t_node_data	*data_a0;
	int			chunk_number;
	int			i;
	int			moves;

	moves = 0;
	while (ft_lstsize(*stack_a) > v.chunk_size)
	{
		chunk_number = ft_get_faster_chunk(*stack_a, v.chunk_size);
		i = 0;
		while (i < v.chunk_size)
		{
			data_a0 = (*stack_a)->content;
			if (data_a0->ele >= chunk_number * v.chunk_size
				&& data_a0->ele < (chunk_number + 1) * v.chunk_size)
			{
				moves += ft_execute_operation("pb", &(*stack_a), &(*stack_b),
						v.exe);
				i++;
			}
			moves += ft_execute_operation("ra", &(*stack_a), &(*stack_b),
					v.exe);
		}
	}
	return (moves);
}

// algorithm 6
// version: 1.0
// sort a stacks with lots of elements
int	ft_algorithm_6(t_list **stack_a, t_list **stack_b, t_variables v)
/* int v.chunk_size, int exe, int moves_record */
{
	int			moves;
	t_variables	v;

	moves = ft_push_chunks(&(*stack_a), &(*stack_b), v);
	while (*stack_a)
		moves += ft_execute_operation("pb", &(*stack_a), &(*stack_b), v.exe);
	v.size = ft_lstsize(*stack_b);
	v.modo = 2;
	moves += ft_algorithm_2(&(*stack_b), &(*stack_a), v);

	return (moves);
}
