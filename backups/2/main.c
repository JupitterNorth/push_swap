/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:29:13 by gabriel           #+#    #+#             */
/*   Updated: 2023/11/27 12:30:41 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_files/push_swap.h"
#include <stdio.h>

/* static void	ft_error(void)
{
	printf("error");
} */

/* static int	*ft_args_to_numbers(int ac, char *av[])
{
	int	i;
	int	*nb_list;

	i = 0;
	nb_list = malloc(sizeof(int) * (ac - 1));
	while (i < ac - 1)
	{
		if (!ft_atoi(av[i + 1]) || ft_nb_already_exist(nb_list, ft_atoi(av[i
					+ 1]), (i)))
			return (0);
		nb_list[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (nb_list);
} */

// static void	printArrayWithPosition(int arr[], int size)
// {
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("Element at position %d: %d\n", i, arr[i]);
// 	}
// }


int	main(int ac, char *av[])
{
	int	*nb_list;

	if (ac >= 2)
	{
		nb_list = ft_args_to_numbers(ac, av);
		if (nb_list)
		{
			ft_push_swap(nb_list, ac - 1);
			printf("ok");
			free(nb_list);
		}
		else
			ft_error();
	}
	else
		ft_error();
	return (0);
}

/* //ft_stack_creation
int main()
{
	int array[] = {23, 42, 9, 5, 2};
	t_list		*stack;
	t_node_data	*data;
	
	stack = ft_stack_creation(array, 5);
	printf("--(%d)--", ft_lstsize(stack));

	for (size_t i = 0; i < 5; i++)
	{
		data = stack->content;
		printf("\n"
		"\nelemento: %d"
		"\nnumero: %d"
		"\nposicao: %d"
		"\n"
		, data->ele, data->nb, data->pos);
		stack = stack->next;
	}
	
	
} */
