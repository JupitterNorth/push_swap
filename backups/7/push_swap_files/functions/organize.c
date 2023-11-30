/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:19:34 by gneto-co          #+#    #+#             */
/*   Updated: 2023/11/28 21:49:01 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_organize_stack(t_list **stack)
{
	int i;
	t_list *temp;
	t_node_data *data;

	if (!stack)
		return ;
	temp = (*stack);
	i = 0;
	while (i < ft_lstsize(*stack))
	{
		data = temp->content;
		data->pos = i;
		temp = temp->next;
		i++;
	}
}
