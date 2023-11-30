/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _menu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:27:56 by gneto-co          #+#    #+#             */
/*   Updated: 2023/11/30 16:48:02 by gneto-co         ###   ########.fr       */
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
    char *args = "30 20 10 40 50 70 60"; 
    // char *args = "56 17 92 41 30 83 12 68 75 6 49 23 88 7 98 34 51 19 63 85"; 

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
        else if (i == 'q')
        {
            system("rm .menu");
            system("clear");
            exit(0);
        }
    }
}