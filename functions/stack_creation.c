/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:29:22 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/02 19:01:28 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_get_array_order(int *nb_list, int size, int pos)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (nb_list[pos] > nb_list[i])
			count++;
		i++;
	}
	return (count);
}

static t_node_data	*ft_data_creation(int *nb_list, int size, int i)
{
	t_node_data	*data;

	data = malloc(sizeof(t_node_data));
	if (!data)
		return (0);
	data->nb = nb_list[i];
	data->pos = i;
	data->ele = ft_get_array_order(nb_list, size, i);
	return (data);
}

t_list	*ft_stack_creation(int *nb_list, int size)
{
	int			i;
	t_list		*stack;
	t_node_data	*data;

	i = 0;
	stack = 0;
	while (i < size)
	{
		data = ft_data_creation(nb_list, size, i);
		ft_lstadd_back(&stack, ft_lstnew(data));
		i++;
	}
	return (stack);
}
