/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:10:01 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/02 18:53:09 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	*data_dup(void *void_data)
{
	t_node_data	*data;
	t_node_data	*new_data;

	data = (t_node_data *)void_data;
	new_data = malloc(sizeof(t_node_data));
	if (!new_data)
		return (NULL);
	new_data->nb = data->nb;
	new_data->pos = data->pos;
	new_data->ele = data->ele;
	return (new_data);
}

static void	ft_big_sort_initializations(t_list *stack_a, t_variables *v)
{
	v->stack_size = ft_lstsize(stack_a);
	v->moves_record = op_square(v->stack_size);
	v->chunk_size = v->stack_size / 10;
	v->best_chunk_size = 0;
	v->exe = 0;
}

static int	ft_big_sort(t_list **stack_a, t_list **stack_b, double div_num)
{
	t_variables	v;
	t_list		*stack_test_a;
	t_list		*stack_test_b;

	ft_big_sort_initializations(*stack_a, &v);
	while (v.chunk_size < (v.stack_size - ((v.stack_size / 10) * div_num)))
	{
		stack_test_a = ft_lstdup(*stack_a, free, data_dup);
		stack_test_b = ft_lstdup(*stack_b, free, data_dup);
		v.moves = ft_algorithm_6(&stack_test_a, &stack_test_b, v);
		if (v.moves_record == 0)
			v.moves_record = v.moves;
		else if (v.moves < v.moves_record)
		{
			v.moves_record = v.moves;
			v.best_chunk_size = v.chunk_size;
		}
		ft_lstclear(&stack_test_a, free);
		ft_lstclear(&stack_test_b, free);
		v.chunk_size++;
	}
	v.chunk_size = v.best_chunk_size;
	v.exe = 1;
	v.moves = ft_algorithm_6(&(*stack_a), &(*stack_b), v);
	return (v.moves);
}

int	ft_sort_stack(t_list **stack_a, t_list **stack_b)
{
	t_variables	v;

	v.exe = 1;
	v.modo = 1;
	v.size = ft_lstsize(*stack_a);
	if (ft_lstsize(*stack_a) == 2)
		return (ft_execute_operation("sa", &(*stack_a), &(*stack_b), 1));
	else if (ft_lstsize(*stack_a) == 3)
		return (ft_algorithm_4(&(*stack_a), &(*stack_b)));
	else if (ft_lstsize(*stack_a) <= 5)
		return (ft_algorithm_5(&(*stack_a), &(*stack_b)));
	else if (ft_lstsize(*stack_a) <= 50)
		return (ft_algorithm_2(&(*stack_a), &(*stack_b), v));
	else if (ft_lstsize(*stack_a) <= 100)
		return (ft_big_sort(&(*stack_a), &(*stack_b), 6));
	else if (ft_lstsize(*stack_a) <= 500)
		return (ft_big_sort(&(*stack_a), &(*stack_b), 8.5));
	return (0);
}
