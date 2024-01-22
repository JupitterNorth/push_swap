/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:27:56 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/19 14:46:33 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"

// run that in your computer
//  cc .menu/* -o .menu_exe && ./.menu_exe
// or that if you are in a stupid 42 computer
//  cc .menu/* && ./a.out

char		g_name[] = "push_swap";
char		*g_args;

#pragma region ex_number

static void ex_0(void)
{
	int a = 0;
	int b = 0;
	int nb = 0;

	while (b != 'q')
	{
		fflush(stdout);
		system("clear");
		printf("\033]0;Chose Values\007");
		printf(
			"\n\nActual arguments: %s\n\n"
			"\n\nChose test values:\n"
			"\n\033[93m 1\x1b[0m 2 random numbers"
			"\n\033[93m 2\x1b[0m 3 random numbers"
			"\n\033[93m 3\x1b[0m 5 random numbers"
			"\n\033[93m 4\x1b[0m 100 random numbers"
			"\n\033[93m 5\x1b[0m 500 random numbers"
			"\n\033[92m r\x1b[0m n random numbers"
			"\n\x1b[31m q\x1b[0m quit"
			"\n\n> ", g_args
			);
		a = getchar();
		b = 'q';
		if (a == '1')
			nb = 2;
		else if (a == '2')
			nb = 3;
		else if (a == '3')
			nb = 5;
		else if (a == '4')
			nb = 100;
		else if (a == '5')
			nb = 500;
		else if (a == 'r')
		{
			fflush(stdout);
			printf("\nInsert the amount of random numbers\n\n> ");
			scanf(" %d", &nb);
		}
		else
			b = a;
	}
	g_args = ft_multi_strjoin("$(shuf -i 1-900 -n %d | tr \"\n\" \" \") ", nb);
	system("clear");
}

static void	ex_1(void)
{
	char	*str;
	int		j;

	j = 0;
	str = ft_multi_strjoin(" ./%s %s", g_name, g_args);
	system(str);
	free(str);
}
static void	ex_2(void)
{
	char	*str;

	str = ft_multi_strjoin("valgrind ./%s %s", g_name, g_args);
	system(str);
	free(str);
}

static void	ex_3(void)
{
	system("make re");
}

static void	ex_4(void)
{
	system("make fclean");
}

static void	ex_5(void)
{
	char *ex;
	int j = 0;
	
	ex = ft_multi_strjoin("ARG=%s; ./%s $ARG | ./checker_OS $ARG", g_args, g_name);
	system(ex);
	free(ex);
}
#pragma endregion

#pragma region ex_letter

static void	ex_g(void)
{
    char    *order;
    char    *commit = NULL;
	char	c = 0;
	size_t len = 0;
	ssize_t read;
    
	system("cd ..");
	printf("\033]0;GitHub Menu\007");
	while (c != 'q')
	{
		fflush(stdout);
		printf
		(
			"\nChose your git command:\n"
			"\n\033[34m 1\x1b[0m add & commit"
			"\n\033[34m 2\x1b[0m push"
			"\n\033[34m 3\x1b[0m pull"
			"\n\033[34m 4\x1b[0m log"
			"\n ---------"
			"\n\033[36m c\x1b[0m clear screen"
			"\n\033[31m q\x1b[0m to quit"
			"\n\n> "
		);
		scanf(" %c", &c);
		getchar();

		system("clear");

		if (c == 'q')
			break;
		else if (c == '1')
		{
			printf("\nType your commit message: \n> ");
			read = getline(&commit, &len, stdin);
			if (commit[read - 1] == '\n')
				commit[read - 1] = '\0';
			order = ft_multi_strjoin("git add . && git commit -m \"%s\"", commit);
			system(order);
			free(order);
			free(commit);
		}
		else if (c == '2')
			system("git push && git log");
		else if (c == '3')
			system("git pull");
		else if (c == '4')
			system("git log");
	}
	system(g_name);
	system("clear");
}

static void	ex_n(void)
{
	system("clear");
	printf("\033[34mnorminette test (only errors): \033[0m\n");
	system("find . -type d -name '.menu' -prune -o -type f \\( -name '*.c' -o -name '*.h' \\) -exec norminette {} \\; | grep -E 'Error|Warning'");
	// system("find . -type f \\( -name '*.c' -o -name '*.h' \\) ! -name '.menu/*' -exec norminette {} \\; | grep -E 'Error|Warning'");
}

static void	ex_r(void)
{
    system("cc .menu/* -o .menu_exe_temp && mv .menu_exe_temp .menu_exe && ./.menu_exe");
	exit(0);
}

static void	ex_q(void)
{
	system("rm .menu_exe");
	system("clear");
	exit(0);
}

static void ex_b(void)
{
	int nb = 0;
	int fd;
	char *str;
	system("mkdir backups");
	system("ls backups > backups/.bk.txt");
	fd = open("backups/.bk.txt", O_RDONLY);
	while((str = get_next_line(fd)))
	{
		nb = ft_atoi(str);
		free(str);
	}
	nb++;
	str = ft_multi_strjoin("rsync -av --exclude=\".git\" --exclude=\".*\" --exclude=\"backups\" . ./backups/%d",nb);
	system(str);
	system("rm backups/.bk.txt && clear");
	printf("\n\033[32mBackup number %d created\x1b[0m\n", nb);
	free(str);
}

#pragma endregion

static char	main_menu()
{	
	char	c;
	
	fflush(stdout);
	printf("\033]0;Test Menu\007");
	printf
	(
		"\nExecute:\n"
		"\n\033[94m 0\x1b[0m chose your test numbers"
		"\n\033[93m 1\x1b[0m ./%s"
		"\n\033[93m 2\x1b[0m valgrind ./%s"
		"\n\033[32m 3\x1b[0m make re"
		"\n\033[32m 4\x1b[0m make fclean"
		"\n\033[95m 5\x1b[0m checker_OS"
		"\n ---------"
		"\n\033[94m g\x1b[0m git menu"
		"\n\033[95m n\x1b[0m norminette"
		"\n\033[91m b\x1b[0m create new backup"
		"\n\033[36m c\x1b[0m clear screen"
		"\n\033[31m r\x1b[0m to reload"
		"\n\033[31m q\x1b[0m to quit"
		"\n\n> "
		,g_name,g_name
	);
	scanf(" %c", &c);
	return (c);
}

static void	sort_number(char c)
{
	if (c == '0')
		ex_0();
	else if (c == '1')
		ex_1();
	else if (c == '2')
		ex_2();
	else if (c == '3')
		ex_3();
	else if (c == '4')
		ex_4();
	else if (c == '5')
		ex_5();
	else if (c == 'g')
		ex_g();
	else if (c == 'n')
		ex_n();
	else if (c == 'b')
		ex_b();
	else if (c == 'r')
		ex_r();
	else if (c == 'q')
		ex_q();
}

int	main(void)
{
	char	c;

	c = 0;
	system("clear");
	while (c != 'q')
	{
		c = main_menu();
		system("clear");
		sort_number(c);
	}
}
