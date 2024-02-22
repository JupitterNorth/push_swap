/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:14 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/22 20:29:14 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_load_data(t_list *stack, t_node_data **data_0)
{
	if (stack)
		(*data_0) = stack->content;
}

// static int	ft_algorithm_1_2(t_list **stack_a, t_list **stack_b,
// 		t_variables v)
// {
// 	t_node_data	*data_a0;
// 	t_node_data	*data_a1;
// 	t_node_data	*data_aa;
// 	int			moves;

// 	v.half = (ft_lstsize(*stack_a)) / 2;
// 	data_aa = ft_get_smallest_element(*stack_a, v.size);
// 	ft_load_data(*stack_a, &data_a0, &data_a1);
// 	moves = 0;
// 	if ((*stack_a)->next)
// 	{
// 		while (data_a0 != data_aa)
// 		{
// 			data_aa = ft_get_smallest_element(*stack_a, v.size);
// 			if (data_aa->pos < v.half)
// 				moves += ft_execute_operation("ra", &(*stack_a), &(*stack_b),
// 						v.exe);
// 			else
// 				moves += ft_execute_operation("rra", &(*stack_a), &(*stack_b),
// 						v.exe);
// 			ft_load_data(*stack_a, &data_a0, &data_a1);
// 		}
// 	}
// 	moves += ft_execute_operation("pb", &(*stack_a), &(*stack_b), v.exe);
// 	return (moves);
// }

// int	ft_algorithm_1(t_list **stack_a, t_list **stack_b, t_variables v)
// {
// 	int	moves;
// 	int	i;

// 	moves = 0;
// 	i = 0;
// 	while (i < v.size)
// 	{
// 		if (v.modo == 1)
// 			moves += ft_algorithm_2_mod1(&(*stack_a), &(*stack_b), v);
// 		else
// 			moves += ft_algorithm_2_mod2(&(*stack_a), &(*stack_b), v);
// 		i++;
// 	}
// 	if (v.modo == 1)
// 	{
// 		while (i)
// 		{
// 			moves += ft_execute_operation("pa", &(*stack_a), &(*stack_b),
// 					v.exe);
// 			i--;
// 		}
// 	}
// 	return (moves);
// }

typedef struct s_chunk
{
	int			max_chunk;
	int			chunk_size;
	int			actual_chunk;
}				t_chunk;

void	change_to_stack_b(t_node_data *member_position, t_list **stack_a, t_list **stack_b)
{
	t_node_data	*data_a0;
    
    ft_load_data(*stack_a, &data_a0);
	while (data_a0 != member_position)
	{
		if (member_position->pos < (ft_lstsize(*stack_a)) / 2)
			ft_execute_operation("ra", &(*stack_a), &(*stack_b), 1);
		else
			ft_execute_operation("rra", &(*stack_a), &(*stack_b), 1);
        ft_load_data(*stack_a, &data_a0);
	}
    ft_execute_operation("pb", &(*stack_a), &(*stack_b), 1);
}

void	change_to_stack_a(t_node_data *member_position, t_list **stack_a, t_list **stack_b)
{
	t_node_data	*data_b0;
    
    ft_load_data(*stack_b, &data_b0);
	while (data_b0 != member_position)
	{
		if (member_position->pos < (ft_lstsize(*stack_b)) / 2)
			ft_execute_operation("rb", &(*stack_a), &(*stack_b), 1);
		else
			ft_execute_operation("rrb", &(*stack_a), &(*stack_b), 1);
        ft_load_data(*stack_b, &data_b0);
	}
    ft_execute_operation("pa", &(*stack_a), &(*stack_b), 1);
}

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

int	ft_algorithm_1(t_list **stack_a, t_list **stack_b)
{
	t_chunk	c;
	t_node_data	*hold_first;
	t_node_data	*hold_last;
	int		i;

	c = chunk_calculations(stack_a);
	while (*stack_a)
	{
        i = 0;
		while (i < c.chunk_size && *stack_a)
		{
            hold_first = ft_get_first_element_on_range(*stack_a, c.actual_chunk * c.chunk_size, ((c.actual_chunk + 1) * c.chunk_size) - 1);
            hold_last = ft_get_last_element_on_range(*stack_a, c.actual_chunk * c.chunk_size, ((c.actual_chunk + 1) * c.chunk_size) - 1);
            // printf("\nhold_first: %d \nhold_last: %d\n\n", hold_first->ele, hold_last->ele);
            if (hold_first->pos < (ft_lstsize(*stack_a) - hold_last->pos))
            {
                // printf("\n\nfirst\n\n");
				change_to_stack_b(hold_first, &(*stack_a), &(*stack_b));
            }
			else
            {
                // printf("\n\nlast\n\n");   
				change_to_stack_b(hold_last, &(*stack_a), &(*stack_b));
            }
			i++;
		}
		c.actual_chunk++;
	}
    
	while (*stack_b)
    {
        t_node_data	*el;
        
        el = ft_get_higher_element(*stack_b, ft_lstsize(*stack_b));
        // printf("\n%d", el->ele);
		change_to_stack_a(el, &(*stack_a), &(*stack_b));
    }
	return (0);
}
