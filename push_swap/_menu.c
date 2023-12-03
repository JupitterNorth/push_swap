/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _menu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:27:56 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/03 16:17:56 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <time.h>

//run that in your file
//cc _menu.c -o .menu && ./.menu

int long	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_menu_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*newstr;

	i = 0;
	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstr == NULL)
		return (0);
	while (*s1)
	{
		newstr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		newstr[i] = *s2;
		i++;
		s2++;
	}
	newstr[i] = '\0';
	return (newstr);
}

int main()
{
    char i = 0;
    //ex0 - 5nb
    // char *args = "30 50 10 40 20";
    //ex1 - 7nb
    // char *args = "-30 20 10 40 50 70 60";
    //ex2 - 20nb
    // char *args = "56 17 92 41 30 83 12 68 75 6 49 23 88 7 98 34 51 19 63 85"; 
    //ex3 - 50nb
    // char *args = "-53 -87 25 -46 -38 -72 39 -91 62 54 -19 70 11 26 47 -95 -63 81 17 -29 -65 88 -10 -56 -74 33 98 92 42 -84 76 -60 3 61 -5 -30 96 58 -12 -47 36 -4 -57 -21 -32 44 -16 -40 7 68 22 74";
    //ex4 - 100nb 
    // char *args = "-62 45 -86 73 37 -51 94 56 -18 -27 82 30 -74 12 66 -4 -95 -21 61 19 53 -32 -79 88 6 25 -9 71 -40 -65 78 -56 97 -15 -48 22 -83 10 -37 68 -99 40 29 7 -60 -2 85 91 18 -24 42 50 -93 36 14 80 -98 63 38 84 -44 -71 -3 51 -90 -13 -77 98 17 69 59 -53 -8 96 -35 -69 23 55 -58 -46 33 -78 -89 20 -5 47 -64 92 -26 75 11 -97 -52 28 76 -70 34 87 -23 44 -34 72";
    
    system("clear");   
    while(i != 'q')
    {
        printf("\033]0;Test Menu\007");
        
        printf(
            "\nExecute:\n"
            "\n\033[93m 1\x1b[0m ./push_swap"
            "\n\033[93m 2\x1b[0m valgrind ./push_swap"
            "\n\033[32m 3\x1b[0m make re"
            "\n\033[32m 4\x1b[0m make fclean"
            "\n\033[34m 5\x1b[0m git commit"
            "\n\033[35m 6\x1b[0m norminette"
            "\n\033[35m 7\x1b[0m checker"
            "\n\x1b[31m r\x1b[0m to reload"
            "\n\x1b[31m q\x1b[0m to quit"
            "\n\n> "
        );
        scanf(" %c", &i);
        system("clear");
        if (i == '1')
        {
            char *str;
            str = ft_menu_strjoin("./push_swap ", args);
            system(str);
            free(str);
        }
        else if (i == '2')
        {
            char *str;
            str = ft_menu_strjoin("valgrind ./push_swap ", args);
            system(str);
            free(str);
        }
        else if (i == '3')
        {
            system("make re");
        }
        else if (i == '4')
        {
            system("make fclean");
        }
        else if (i == '5')
        {
            system("git add ../* && git commit -m \"bk\" && git push && git log");
        }
        else if (i == '6')
        {
            system("clear");
            printf("\033[34mnorminette test (only errors): \033[0m\n");
            system("find . -type f \\( -name '*.c' -o -name '*.h' \\) ! -name '_tester.c' -exec norminette {} \\; | grep -E 'Error|Warning'");
        }
        else if (i == '7')
        {
            // ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
            system(
                "ARG=\"30 20 10 40 50 70 60\"; ./push_swap $ARG | ./checker_OS $ARG"
            );
        }        
        else if (i == 'r')
        {
            system("cc _menu.c -o .menu && ./.menu");
            exit(0);
        }
        else if (i == 'q')
        {
            system("rm .menu");
            system("clear");
            exit(0);
        }
    }
}