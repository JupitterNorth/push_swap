/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _menu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:27:56 by gneto-co          #+#    #+#             */
/*   Updated: 2023/12/22 12:33:54 by gneto-co         ###   ########.fr       */
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


char *g_ex5 = 
			"588	470	199	863	646	397	463	 39	644	 79	 61	679	640	425	372	 17	554	610	 27	428	"
			"380	200	460	779	600	435	527	174	755	614	842	625	-55	287	540	803	769	419	338	487	"
			" 52	275	469	643	121	473	-68	537	884	-32	732	508	176	453	-78	265	752	450	340	443	"
			" 48	885	856	593	723	285	367	-26	 85	581	686	797	899	134	268	657	694	 93	713	407	"
			"432	156	 41	544	181	872	301	804	-14	878	523	598	308	489	894	541	695	651	507	-76	"
			"809	521	811	451	617	313	739	222	859	840	315	312	568	724	799	236	587	158	-90	-67	"
			"420	256	302	260	729	266	608	166	333	669	196	373	748	865	440	730	-71	557	745	759	"
			"-89	184	320	 50	281	868	149	 53	474	344	 26	 24	495	226	-57	-19	851	201	168	127	"
			"471	-64	383	886	753	770	219	628	 44	529	788	393	 63	111	253	531	711	895	-54	762	"
			"546	122	189	374	205	 98	220	896	392	-34	165	289	 28	-63	-28	594	825	212	371	186	"
			"-38	273	-44	123	742	 -3	101	362	866	888	509	395	342	-27	159	112	538	105	621	626	"
			"290	-84	853	-15	-60	324	274	833	 45	702	582	638	477	744	 80	778	623	163	 55	  8	"
			" 91	645	765	-18	876	814	322	749	108	323	341	583	515	530	655	-41	 -2	796	497	309	"
			"787	117	233	768	441	481	237	629	575	216	548	701	235	658	816	-22	139	705	141	337	"
			"900	718	559	720	491	663	-37	364	791	766	388	496	 83	361	283	439	249	668	877	452	"
			"855	607	126	  7	129	571	446	243	881	880	161	454	424	 16	867	675	282	-52	218	504	"
			" 71	  6	227	561	622	602	 62	836	160	-20	649	555	109	818	 58	394	566	291	257	462	"
			"240	284	230	642	 87	677	 14	 86	135	353	307	875	673	 72	889	737	722	 15	 40	580	"
			"611	386	519	-72	-42	363	719	786	484	567	154	164	262	 43	746	800	-66	206	328	152	"
			"332	549	297	194	 64	417	310	775	716	743	391	-21	437	213	254	510	294	870	874	648	"
			"585	681	244	404	193	375	824	480	552	-40	562	248	-81	408	564	747	726	330	789	354	"
			"445	 22	-50	241	656	741	306	 34	336	125	-83	130	 -4	513	570	131	698	270	511	 57	"
			"839	847	631	267	 21	390	520	464	630	415	448	-73	591	179	104	150	849	180	427	 66	"
			"247	573	479	358	 37	776	368	898	490	-75	584	652	636	750	 51	666	542	414	 54	113	"
			"553	335	 77	 65	606	214	239	 67	-74	385	-17	447	215	 11	316	518	828	822	795	472";

int main()
{
    char i = 0;
    int random;
    char *args = g_ex5;
    
    system("clear");   
    while(i != 'q')
    {
	    fflush(stdout);
        printf("\033]0;Test Menu\007");
        
        printf(
            "\nExecute:\n"
            "\n\033[91m 0\x1b[0m test values"
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
        else if (i == '0')
        {
            int a = 0;
            int b = 0;
            while (b != 'q')
            {
            	fflush(stdout);
                system("clear");
                printf("\033]0;Chose Values\007");
                printf(
                    "\nActual number %d"
                    "\nChose test values:\n"
                    "\n\033[93m 1\x1b[0m ex1 - 7 numbers"
                    "\n\033[93m 2\x1b[0m ex2 - 20 numbers"
                    "\n\033[93m 3\x1b[0m ex3 - 50 numbers"
                    "\n\033[93m 4\x1b[0m ex4 - 100 numbers"
                    "\n\033[93m 5\x1b[0m ex5 - 500 numbers"
                    "\n\033[92m r\x1b[0m random x numbers"
                    "\n\x1b[31m q\x1b[0m quit"
                    "\n\n> ", random
                    );
                a = getchar();
                b = 'q';
                if (a == '1')
                    args = "-30 20 10 40 50 70 60";
                else if (a == '2')
                    args = "56 17 92 41 30 83 12 68 75 6 49 23 88 7 98 34 51 19 63 85";
                else if (a == '3')
                    args = "-53 -87 25 -46 -38 -72 39 -91 62 54 -19 70 11 26 47 -95 -63 81 17 -29 -65 88 -10 -56 -74 33 98 92 42 -84 76 -60 3 61 -5 -30 96 58 -12 -47 36 -4 -57 -21 -32 44 -16 -40 7 68 22 74";
                else if (a == '4')
                    args = "-62 45 -86 73 37 -51 94 56 -18 -27 82 30 -74 12 66 -4 -95 -21 61 19 53 -32 -79 88 6 25 -9 71 -40 -65 78 -56 97 -15 -48 22 -83 10 -37 68 -99 40 29 7 -60 -2 85 91 18 -24 42 50 -93 36 14 80 -98 63 38 84 -44 -71 -3 51 -90 -13 -77 98 17 69 59 -53 -8 96 -35 -69 23 55 -58 -46 33 -78 -89 20 -5 47 -64 92 -26 75 11 -97 -52 28 76 -70 34 87 -23 44 -34 72";
                else if (a == '5')
					args = g_ex5;
				else if (a == 'r')
                {
            	    fflush(stdout);
                    printf("\nInsert the amount of random numbers\n\n> ");
                    scanf(" %d", &random);
                    args = "$(shuf -i 1-900 -n ";
                    char string_numero[20];
                
                    sprintf(string_numero, "%d", random);
                    
                    args = ft_menu_strjoin(args ,string_numero);
                    args = ft_menu_strjoin(args ," | tr \"\n\" \" \")");
                }
                else
                    b = a;
            }
            system("clear");
            // printf("argumento atual: %s\n", args);
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
