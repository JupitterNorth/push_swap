/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:29:13 by gabriel           #+#    #+#             */
/*   Updated: 2024/01/10 11:55:56 by gneto-co         ###   ########.fr       */
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

// void	ft_table_stacks(t_list *stack_a, t_list *stack_b)
// {
// 	int			i;
// 	int			size_a;
// 	int			size_B;
// 	size_a = ft_lstsize(stack_a);
// 	size_B = ft_lstsize(stack_b);
// 	t_node_data	*data_A[size_a];
// 	t_node_data	*data_b[size_B];

// 	i = 0;
// 	while (i < size_a)
// 	{
// 		data_A[i] = stack_a->content;
// 		stack_a = stack_a->next;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < size_B)
// 	{
// 		data_b[i] = stack_b->content;
// 		stack_b = stack_b->next;
// 		i++;
// 	}
// 	i = 0;
// 	printf("\n┌─────┬─────┬─────┐┌─────┬─────┬─────┐"
// 			"\n│  A  │ ele │ num ││  B  │ ele │ num │");
// 	while (i < size_a || i < size_B)
// 	{
// 		printf("\n├─────┼─────┼─────┤├─────┼─────┼─────┤\n");
// 		if (i < size_a)
// 			printf("│ %3d │ %3d │ %3d │", data_A[i]->pos, data_A[i]->ele,
// 				data_A[i]->nb);
// 		else
// 			printf("│     │     │     │");
// 		if (i < size_B)
// 			printf("│ %3d │ %3d │ %3d │", data_b[i]->pos, data_b[i]->ele,
// 				data_b[i]->nb);
// 		else
// 			printf("│     │     │     │");
// 		i++;
// 	}
// 	printf("\n└─────┴─────┴─────┘└─────┴─────┴─────┘\n");
// 	fflush(stdout);
// }

// static int	check_errors(int *nb_list, char *av[], int i)
// {
// 	if (!ft_atoi(av[i]))
// 		if (ft_strncmp(av[i], "0", 2))
// 			return (0);
// 	if (ft_nb_already_exist(nb_list, ft_atoi(av[i]), i))
// 		return (0);
// 	return (1);
// }

// static int	*ft_args_to_numbers(int ac, char *av[])
// {
// 	int	i;
// 	int	*nb_list;

// 	i = 0;
// 	nb_list = malloc(sizeof(int) * (ac));
// 	while (i < ac)
// 	{
// 		if (!check_errors(nb_list, av, i))
// 		{
// 			free(nb_list);
// 			return (0);
// 		}
// 		nb_list[i] = ft_atoi(av[i]);
// 		i++;
// 	}
// 	return (nb_list);
// }

// #include <fcntl.h>
// int main(int ac, char *av[])
// {
// 	(void)ft_error;

// 	if (ac != 2)
// 		return (0);

// 	int fd = open(av[1], O_RDONLY);

// 	int		size = 51;

// 	char	*op;

// 	char	numbers[] = " 82 623 177 78 149 413 878 561 300 439 202 86 625 694 791 285 69 5 308 53 845 784 221 715 244 636 630 683 48 100 235 752 851 265 227 753 383 167 316 690 297 526 295 887 267 208 375 790 830 700 287 ";
// 	char	**numbers_lst = ft_split(numbers, ' ');
// 	int		*nb_list = ft_args_to_numbers(size, numbers_lst);
// 	ft_putnbr(nb_list[0]);

// 	t_list	*stack_a = ft_stack_creation(nb_list, size);
// 	t_list	*stack_b = ft_stack_creation(NULL, 0);

// 	printf("\n---------- Original Stack ----------");
// 	ft_table_stacks(stack_a, stack_b);

// 	while (1)
// 	{
// 		op = get_next_line(fd);

// 		if (!op)
// 			break ;

// 		int i = 0;
// 		char	order[3];
// 		while (op[i])
// 		{
// 			if (op[i] != '\n')
// 				order[i] = op[i];
// 			i++;
// 		}

// 		ft_putstr("\n -- ");
// 		ft_putstr(order);
// 		ft_putstr(" -- \n");
// 		ft_execute_operation(order, &stack_a, &stack_b, 1);

// 		free(op);
// 	}

// 	ft_lstclear(&stack_a, free);
// 	ft_lstclear(&stack_b, free);
// 	free(nb_list);

// 	int i = 0;
// 	while (numbers_lst[i])
// 		free(numbers_lst[i++]);
// 	free(numbers_lst);

// 	close(fd);
// }