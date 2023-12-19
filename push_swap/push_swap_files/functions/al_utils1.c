/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:11:14 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/19 18:50:37 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_table_stacks(t_list *stack_A, t_list *stack_B)
{
	int			i;
	int			size_A;
	int			size_B;
	size_A = ft_lstsize(stack_A);
	size_B = ft_lstsize(stack_B);
	t_node_data	*data_A[size_A];
	t_node_data	*data_B[size_B];

	i = 0;
	while (i < size_A)
	{
		data_A[i] = stack_A->content;
		stack_A = stack_A->next;
		i++;
	}
	i = 0;
	while (i < size_B)
	{
		data_B[i] = stack_B->content;
		stack_B = stack_B->next;
		i++;
	}
	i = 0;
	printf("\n┌─────┬─────┬─────┐┌─────┬─────┬─────┐"
			"\n│  A  │ ele │ num ││  B  │ ele │ num │");
	while (i < size_A || i < size_B)
	{
		printf("\n├─────┼─────┼─────┤├─────┼─────┼─────┤\n");
		if (i < size_A)
			printf("│ %3d │ %3d │ %3d │", data_A[i]->pos, data_A[i]->ele,
				data_A[i]->nb);
		else
			printf("│     │     │     │");
		if (i < size_B)
			printf("│ %3d │ %3d │ %3d │", data_B[i]->pos, data_B[i]->ele,
				data_B[i]->nb);
		else
			printf("│     │     │     │");
		i++;
	}
	printf("\n└─────┴─────┴─────┘└─────┴─────┴─────┘\n");
	fflush(stdout);
}

int	ft_execute_operation(char *op, t_list **stack_A, t_list **stack_B)
{
	ft_putstr(op);
	ft_putstr("\n");
	if (!ft_strncmp(op, "sa", 2))
		operation_sa(&(*stack_A));
	else if (!ft_strncmp(op, "sb", 2))
		operation_sb(&(*stack_B));
	else if (!ft_strncmp(op, "ss", 2))
		operation_ss(&(*stack_A), &(*stack_B));
	else if (!ft_strncmp(op, "pa", 2))
		operation_pa(&(*stack_A), &(*stack_B));
	else if (!ft_strncmp(op, "pb", 2))
		operation_pb(&(*stack_A), &(*stack_B));
	else if (!ft_strncmp(op, "rra", 3))
		operation_rra(&(*stack_A));
	else if (!ft_strncmp(op, "rrb", 3))
		operation_rrb(&(*stack_B));
	else if (!ft_strncmp(op, "rrr", 3))
		operation_rrr(&(*stack_A), &(*stack_B));
	else if (!ft_strncmp(op, "ra", 2))
		operation_ra(&(*stack_A));
	else if (!ft_strncmp(op, "rb", 2))
		operation_rb(&(*stack_B));
	else if (!ft_strncmp(op, "rr", 2))
		operation_rr(&(*stack_A), &(*stack_B));
	//table and pause
	// ft_table_stacks(*stack_A, *stack_B);
	// getchar();
	// end
	return (1);
}

t_node_data	*ft_get_higher_element(t_list *stack)
{
	int			i;
	int			size;
	t_node_data	*element;
	t_node_data	*data;

	i = 0;
	element = stack->content;
	size = ft_lstsize(stack);
	while (i < size)
	{
		data = (stack)->content;
		// ft_putnbr();
		if (data->ele > element->ele)
			element = data;
		i++;
		stack = stack->next;
	}
	return (element);
}

t_node_data	*ft_get_smallest_element(t_list *stack)
{
	int			i;
	int			size;
	t_node_data	*element;
	t_node_data	*data;

	i = 0;
	element = ft_get_higher_element(stack);
	size = ft_lstsize(stack);
	while (i < size)
	{
		data = (stack)->content;
		if (data->ele < element->ele)
			element = data;
		i++;
		stack = stack->next;
	}
	return (element);
}

int	element_on_stack(int element, t_list *stack)
{
	t_node_data	*data;

	if (!stack)
		return (0);
	while (stack->next)
	{
		data = stack->content;
		if (data->ele == element)
			return (1);
		stack = stack->next;
	}
	return (0);
}
