/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:01:08 by gabriel           #+#    #+#             */
/*   Updated: 2023/12/03 13:36:02 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct node_data
{
	int	nb;
	int	pos;
	int	ele;
}		t_node_data;

int		ft_push_swap(int *nb_list, int size);

// functions
t_list	*ft_stack_creation(int *nb_list, int size);
void	ft_organize_stack(t_list **stack);

// operations
void	operation_sa(t_list **stack_A);
void	operation_sb(t_list **stack_B);
void	operation_ss(t_list **stack_A, t_list **stack_B);

void	operation_pa(t_list **stack_A, t_list **stack_B);
void	operation_pb(t_list **stack_A, t_list **stack_B);

void	operation_ra(t_list **stack_A);
void	operation_rb(t_list **stack_B);
void	operation_rr(t_list **stack_A, t_list **stack_B);

void	operation_rra(t_list **stack_A);
void	operation_rrb(t_list **stack_B);
void	operation_rrr(t_list **stack_A, t_list **stack_B);

// algorithm
int		stack_in_order(t_list *stack);
void	al_execution(char *op, t_list **stack_A, t_list **stack_B);
int		ft_sort_stack(t_list **stack_A, t_list **stack_B);
// al 1
int		ft_algorithm_1A(t_list **stack_A, t_list **stack_B, int half);
int		ft_algorithm_1B(t_list **stack_A, t_list **stack_B, int half);
// al 2
int		ft_algorithm_2A(t_list **stack_A, t_list **stack_B);
int		ft_algorithm_2B(t_list **stack_A, t_list **stack_B);

#endif
