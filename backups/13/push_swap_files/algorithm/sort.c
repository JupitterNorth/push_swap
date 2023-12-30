/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:10:01 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/30 01:02:08 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void *data_dup(void *void_data)
{
    t_node_data *data = (t_node_data *)void_data;
    t_node_data *new_data;
    
    new_data = malloc(sizeof(t_node_data));
    if (!new_data)
        return NULL;
    new_data->nb = data->nb;
    new_data->pos = data->pos;
    new_data->ele = data->ele;
    return new_data;
}

// that function belongs to example 2
static int	ft_big_sort(t_list **stack_A, t_list **stack_B, double div_num)
{
	int		chunk_size;
	int		best_chunk_size;
	int		moves_record;
	int		moves;
	int		stack_size;
	t_list	*stack_test_A;
	t_list	*stack_test_B;
	
	stack_size = ft_lstsize(*stack_A);
	moves_record = op_square(stack_size);
	chunk_size = stack_size / 10;
	best_chunk_size = 0;
	while (chunk_size < (stack_size - ((stack_size / 10) * div_num)))
	{
		stack_test_A = ft_lstdup(*stack_A, free, data_dup);
		stack_test_B = ft_lstdup(*stack_B, free, data_dup);
		
		moves = ft_algorithm_6(&stack_test_A, &stack_test_B, chunk_size, 0, moves_record);
					
		if (moves_record == 0)
			moves_record = moves;
		else if (moves < moves_record)
		{
			moves_record = moves;
			best_chunk_size = chunk_size;
		}
		
		printf("\n\n-> %d", chunk_size);
		printf("\n-> %d", moves);
		ft_lstclear(&stack_test_A, free);
		ft_lstclear(&stack_test_B, free);
		chunk_size++;
	}
	printf("\n\n--> %d", best_chunk_size);
	moves = ft_algorithm_6(&(*stack_A), &(*stack_B), best_chunk_size, 1, moves_record);
	return (moves);
}

int	ft_sort_stack(t_list **stack_A, t_list **stack_B)
{	
	if (ft_lstsize(*stack_A) == 2)
		return (ft_execute_operation("sa", &(*stack_A), &(*stack_B), 1));
	else if (ft_lstsize(*stack_A) == 3)
		return (ft_algorithm_4(&(*stack_A), &(*stack_B)));
	else if (ft_lstsize(*stack_A) <= 5)
		return (ft_algorithm_5(&(*stack_A), &(*stack_B)));
	else if (ft_lstsize(*stack_A) <= 50)
		return(ft_algorithm_2(&(*stack_A), &(*stack_B), ft_lstsize(*stack_A), 1, 1));
	
// example 1
	// else
	// int		chunk_size;
	// int		best_chunk_size;
	// int		moves_record;
	// int		moves;
	// int		stack_size;
	// t_list	*stack_test_A;
	// t_list	*stack_test_B;
	// {
	// 	stack_size = ft_lstsize(*stack_A);
	// 	moves_record = op_square(stack_size);
	// 	chunk_size = stack_size / 10;
	// 	best_chunk_size = 0;
	// 	while (chunk_size < (stack_size - ((stack_size / 10) * 8.5)))
	// 	{
	// 		stack_test_A = ft_lstdup(*stack_A, free, data_dup);
	// 		stack_test_B = ft_lstdup(*stack_B, free, data_dup);
			
	// 		moves = ft_algorithm_6(&stack_test_A, &stack_test_B, chunk_size, 0, moves_record);
						
	// 		if (moves_record == 0)
	// 			moves_record = moves;
	// 		else if (moves < moves_record)
	// 		{
	// 			moves_record = moves;
	// 			best_chunk_size = chunk_size;
	// 		}
			
	// 		printf("\n\n-> %d", chunk_size);
	// 		printf("\n-> %d", moves);
	// 		ft_lstclear(&stack_test_A, free);
	// 		ft_lstclear(&stack_test_B, free);
	// 		chunk_size++;
	// 	}
	// 	printf("\n\n--> %d", best_chunk_size);
	// 	moves = ft_algorithm_6(&(*stack_A), &(*stack_B), best_chunk_size, 1, moves_record);
	// 	return (moves);
	// }
	
// example 2
	else if (ft_lstsize(*stack_A) <= 100)
		return(ft_big_sort(&(*stack_A), &(*stack_B), 6));
	else if (ft_lstsize(*stack_A) <= 500)
		return(ft_big_sort(&(*stack_A), &(*stack_B), 8.5));
	
	return (0);
}
