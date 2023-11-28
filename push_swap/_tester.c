/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tester.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:27:56 by gneto-co          #+#    #+#             */
/*   Updated: 2023/11/28 13:55:11 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <time.h>

int main()
{
    char i = 0;

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
            "\n\x1b[31m q\x1b[0m to quit"
            "\n\n> "
        );
        scanf(" %c", &i);
        system("clear");
        if (i == '1')
        {
            system("./push_swap 56 17 92 41 30 83 12 68 75 6 49 23 88 7 98 34 51 19 63 85");
        }
        else if (i == '2')
        {
            system("valgrind ./push_swap 56 17 92 41 30 83 12 68 75 6 49 23 88 7 98 34 51 19 63 85");
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
            system("git add ../* && git commit -m \"bk3\" && git push && git log");
        }
        else if (i == '6')
        {
            system("clear");
            printf("\033[34mnorminette test (only errors): \033[0m\n");
            system("find . -type f \\( -name '*.c' -o -name '*.h' \\) ! -name '_tester.c' -exec norminette {} \\; | grep -E 'Error|Warning'");
        }
        else if (i == '7')
        {
            if (i == '8')
            {
                printf("BANANA");
            }
            
        }
        else if (i == 'q')
        {
            system("rm .tester");
            system("clear");
            exit(0);
        }
    }
}