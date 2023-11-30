/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:29:13 by gabriel           #+#    #+#             */
/*   Updated: 2023/11/30 14:47:02 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_files/push_swap.h"
#include <stdio.h>

static void	ft_error(void)
{
	ft_putstr("Error\n");
}

static int	*ft_args_to_numbers(int ac, char *av[])
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
}

int	main(int ac, char *av[])
{
	int	*nb_list;
	int	moves;

	if (ac >= 2)
	{
		nb_list = ft_args_to_numbers(ac, av);
		if (nb_list)
		{
			moves = ft_push_swap(nb_list, ac - 1);
			printf("\n\nMoves: %d", moves);
			free(nb_list);
		}
		else
			ft_error();
	}
	else
		ft_error();
	return (0);
}
