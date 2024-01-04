/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:01:08 by gabriel           #+#    #+#             */
/*   Updated: 2024/01/04 10:26:52 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct node_data
{
	int		nb;
	int		pos;
	int		ele;
}			t_node_data;

typedef struct variables
{
	int		half;
	int		size;
	int		modo;
	int		exe;
	int		chunk_size;
	int		moves_record;
	int		moves;
	int		best_chunk_size;
	int		stack_size;
}			t_variables;

int			ft_push_swap(int *nb_list, int size);

// operations
void		operation_sa(t_list **stack_a);
void		operation_sb(t_list **stack_b);
void		operation_ss(t_list **stack_a, t_list **stack_b);

void		operation_pa(t_list **stack_a, t_list **stack_b);
void		operation_pb(t_list **stack_a, t_list **stack_b);

void		operation_ra(t_list **stack_a);
void		operation_rb(t_list **stack_b);
void		operation_rr(t_list **stack_a, t_list **stack_b);

void		operation_rra(t_list **stack_a);
void		operation_rrb(t_list **stack_b);
void		operation_rrr(t_list **stack_a, t_list **stack_b);

// functions
t_list		*ft_stack_creation(int *nb_list, int size);
void		ft_organize_stack(t_list **stack);
t_node_data	*ft_get_higher_element(t_list *stack, int max_pos);
t_node_data	*ft_get_smallest_element(t_list *stack, int max_pos);
int			ft_execute_operation(char *op, t_list **stack_a, t_list **stack_b,
				int ex);
int			stack_in_order(t_list *stack);
int			element_on_stack(int element, t_list *stack);

// algorithm
int			ft_sort_stack(t_list **stack_a, t_list **stack_b);
// al 2 - organize a stack
int			ft_algorithm_2(t_list **stack_a, t_list **stack_b, t_variables v);
// al 4 - sort 3 elements
int			ft_algorithm_4(t_list **stack_a, t_list **stack_b);
// al 5 - sort 4/5 elements
int			ft_algorithm_5(t_list **stack_a, t_list **stack_b);
// al 6
int			ft_algorithm_6(t_list **stack_a, t_list **stack_b, t_variables v);
#endif
