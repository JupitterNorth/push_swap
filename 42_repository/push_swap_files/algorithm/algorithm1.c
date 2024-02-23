/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:14 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/23 13:00:27 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_chunk
{
	int			max_chunk;
	int			chunk_size;
	int			actual_chunk;
}				t_chunk;

static t_chunk	chunk_calculations(t_list **stack_a)
{
	t_chunk	c;

	if (ft_lstsize(*stack_a) <= 100)
		c.max_chunk = 5;
	else if (ft_lstsize(*stack_a) > 100)
		c.max_chunk = 11;
	c.chunk_size = ft_lstsize(*stack_a) / c.max_chunk;
	c.actual_chunk = 0;
	return (c);
}

static void	ft_divide_by_chunks(t_list **stack_a, t_list **stack_b)
{
	t_node_data	*hold_first;
	t_node_data	*hold_last;
	t_chunk		c;
	int			i;

	c = chunk_calculations(stack_a);
	while (*stack_a)
	{
		i = 0;
		while (i < c.chunk_size && *stack_a)
		{
			hold_first = ft_get_first_element_on_range(*stack_a, c.actual_chunk
					* c.chunk_size, ((c.actual_chunk + 1) * c.chunk_size) - 1);
			hold_last = ft_get_last_element_on_range(*stack_a, c.actual_chunk
					* c.chunk_size, ((c.actual_chunk + 1) * c.chunk_size) - 1);
			if (hold_first->pos < (ft_lstsize(*stack_a) - hold_last->pos))
				change_to_stack_b(hold_first, &(*stack_a), &(*stack_b));
			else
				change_to_stack_b(hold_last, &(*stack_a), &(*stack_b));
			i++;
		}
		c.actual_chunk++;
	}
}

int	ft_algorithm_1(t_list **stack_a, t_list **stack_b)
{
	t_node_data	*el;

	ft_divide_by_chunks(&(*stack_a), &(*stack_b));
	while (*stack_b)
	{
		el = ft_get_higher_element(*stack_b, ft_lstsize(*stack_b));
		change_to_stack_a(el, &(*stack_a), &(*stack_b));
	}
	return (0);
}
