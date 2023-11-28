/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:01:08 by gabriel           #+#    #+#             */
/*   Updated: 2023/11/28 17:48:05 by gneto-co         ###   ########.fr       */
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

t_list	*ft_stack_creation(int *nb_list, int size);
void	operation_sa(t_list **stack_A);
void	operation_sb(t_list **stack_B);
void	operation_ss(t_list **stack_A, t_list **stack_B);

void	operation_pa(t_list **stack_A, t_list **stack_B);
void	operation_pb(t_list **stack_A, t_list **stack_B);

#endif
