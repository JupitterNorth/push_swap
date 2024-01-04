/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:29:13 by gabriel           #+#    #+#             */
/*   Updated: 2024/01/04 10:44:17 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_files/push_swap.h"
#include <stdio.h>

static void	ft_error(void)
{
	ft_putstr("Error\n");
}

static int	check_errors(int *nb_list, char *av[], int i)
{
	if (!ft_atoi(av[i + 1]))
		if (ft_strncmp(av[i + 1], "0", 2))
			return (0);
	if (ft_nb_already_exist(nb_list, ft_atoi(av[i + 1]), i))
		return (0);
	return (1);
}

static int	*ft_args_to_numbers(int ac, char *av[])
{
	int	i;
	int	*nb_list;

	i = 0;
	nb_list = malloc(sizeof(int) * (ac - 1));
	while (i < ac - 1)
	{
		if (!check_errors(nb_list, av, i))
		{
			free(nb_list);
			return (0);
		}
		nb_list[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (nb_list);
}

int	main(int ac, char *av[])
{
	int	*nb_list;

	if (ac >= 2)
	{
		nb_list = ft_args_to_numbers(ac, av);
		if (nb_list)
		{
			ft_push_swap(nb_list, ac - 1);
			free(nb_list);
		}
		else
			ft_error();
	}
	return (0);
}
