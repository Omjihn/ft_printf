
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include "gnl/get_next_line_bonus.h"
#include "src/ft_printf.h"

#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define WHT "\033[0;37m"

void  ft_free(int fd[2][2], char *res_1, char *res_2)
{
        if (res_1)
                free(res_1);
        res_1 = get_next_line(fd[0][0]);
        while (res_1)
        {
                free(res_1);
                res_1 = get_next_line(fd[0][0]);
        }
        if (res_2)
                free(res_2);
        res_2 = get_next_line(fd[1][0]);
        while (res_2)
        {
                free(res_2);
                res_2 = get_next_line(fd[1][0]);
        }
        close(fd[1][0]);
	close(fd[0][0]);
}

int	main(int ac, char **av)
{
        char *prompt_cs = "%15c | % 12s | %-10.2s | %-12.2147483648s | %02.21c | %s | %2.3s | % -00002s |\n";
	char	arg_1 = 's';
	char	*arg_2 = "Oulala";
	char	*arg_3 = NULL;
	char	*arg_4 = "ljkeyg erkljuhbaoirufghb oeiabnf oekrjuhnagoiash g";
	char	arg_9 = 'B';
	char	*arg_10 = "";
	char	*arg_11 = "kruhn [-0932 2";
	char	*arg_12 = ".......       ........";

	char *prompt_diu = "%+015.7d | %+010.4i | %+-20.15d | % -8.4i | %+u | %032.24u |\n";
	int	arg_5 = INT_MIN;
	int	arg_6 = 0;
	int	arg_7 = INT_MAX;
	int	arg_8 = 48;
	unsigned int	arg_29 = 654345;
	unsigned int	arg_30 = 0;
	
	char *prompt_xX = "%9x | %#012x | %#-15.7X | %#020.15X |\n";
	unsigned int arg_13 = UINT_MAX;
	unsigned int arg_14 = 656325;
	unsigned int arg_15 = 0;
	unsigned int arg_16 = 42;
	
	char *prompt_p = "%-12p | %-40.32p | %020p | %20.15p |\n";
	void	*arg_17 = NULL;
	void	*arg_18 = malloc(0);
	void	*arg_19 = malloc(0);
	void	*arg_20 = malloc(0);
	
	char *prompt_args = "%*d | %.*s | %0*x | %-*c |\n";
	int	arg_21 = 5;
	int	arg_22 = 42;
	int	arg_23 = 9;
	char	*arg_24 = "Ca marche pas";
	int	arg_25 = 12;
	unsigned int arg_26 = 656325;
	int arg_27 = 5;
	char arg_28 = '>';
	
	char *prompt_of = "% 2147483648d | %c\n";
	char *prompt_of_2 = "% -2147483649d | %c\n";
	
	
	
//	char	*prompt_per = "%% | %0954-3]4% | %       % | %54989=084% |\n";
	
	
	if (ac == 2 && !strcmp(av[1], "check"))
	{
		int	fd[2][2];
		
		pipe(fd[0]);
		pipe(fd[1]);
		int	pid_1 = fork();
		if (pid_1 == 0)
		{
			dup2(fd[0][1], STDOUT_FILENO);
			close(fd[0][0]);
			close(fd[0][1]);
			int ret_1 = ft_printf(prompt_cs, arg_1, arg_2, arg_3, arg_4, arg_9, arg_10, arg_11, arg_12);
			int ret_2 = ft_printf(prompt_diu, arg_5, arg_6, arg_7, arg_8, arg_29, arg_30);
			int ret_7 = ft_printf(prompt_xX, arg_13, arg_14, arg_15, arg_16);
			int ret_9 = ft_printf(prompt_p, arg_17, arg_18, arg_19, arg_20);
			int ret_11 = ft_printf(prompt_args, arg_21, arg_22, arg_23, arg_24, arg_25, arg_26, arg_27, arg_28);
			int ret_13 = ft_printf(prompt_of, arg_5);
			int ret_14 = ft_printf(prompt_of_2, arg_5);
//			int ret_5 = ft_printf(prompt_per);
			printf("%d%d%d%d%d%d%d\n", ret_1, ret_2, ret_7, ret_9, ret_11, ret_13, ret_14);
			exit(0);
		}
		int pid_2 = fork();
		if (pid_2 == 0)
		{
			dup2(fd[1][1], STDOUT_FILENO);
			close(fd[1][0]);
			close(fd[1][1]);
			int ret_3 = printf(prompt_cs, arg_1, arg_2, arg_3, arg_4, arg_9, arg_10, arg_11, arg_12);
			int ret_4 = printf(prompt_diu, arg_5, arg_6, arg_7, arg_8, arg_29, arg_30);
			int ret_8 = printf(prompt_xX, arg_13, arg_14, arg_15, arg_16);
			int ret_10 = printf(prompt_p, arg_17, arg_18, arg_19, arg_20);
			int ret_12 = printf(prompt_args, arg_21, arg_22, arg_23, arg_24, arg_25, arg_26, arg_27, arg_28);
			int ret_15 = printf(prompt_of, arg_5);
			int ret_16 = printf(prompt_of_2, arg_5);
//			int ret_6 = printf(prompt_per);
			printf("%d%d%d%d%d%d%d\n", ret_3, ret_4, ret_8, ret_10, ret_12, ret_15, ret_16);
			exit(0);
		}
		waitpid(pid_1, NULL, 0);
		waitpid(pid_2, NULL, 0);
		free(arg_18);
		free(arg_19);
		free(arg_20);
		close(fd[0][1]);
		close(fd[1][1]);
		char *res_1 = NULL;
		char *res_2 = NULL;
		while (1)
		{
			if (res_1)
				free(res_1);
			if (res_2)
				free(res_2);
			res_1 = get_next_line(fd[0][0]);
			res_2 = get_next_line(fd[1][0]);
			if ((!res_1 && res_2) || (!res_2 && res_1))
			{
				printf(RED"FAIL\n"WHT);
				ft_free(fd, res_1, res_2);
				exit(0);
			}
	                else if (!res_1 && !res_2)
			{
				printf(GRN"SUCCESS\n"WHT);
				ft_free(fd, res_1, res_2);
				exit(0);
			}
			else if (strcmp(res_1, res_2))
			{
				printf(RED"FAIL\n"WHT);
				ft_free(fd, res_1, res_2);
				exit(0);
			}
		}
	}
	else
	{
	        printf ("Test 1:\n");
		printf("printf %sArgs : %c | %s | %s | %s | %c | %s | %s | %s |\n", prompt_cs, arg_1, arg_2, arg_3, arg_4, arg_9, arg_10, arg_11, arg_12);
		printf("---------------------------------------------------\n\nft_printf :\n");
		printf("%d\n", ft_printf(prompt_cs, arg_1, arg_2, arg_3, arg_4, arg_9, arg_10, arg_11, arg_12));
		printf("---------------------------------------------------\n\nprintf :\n");
		printf("%d\n", printf(prompt_cs, arg_1, arg_2, arg_3, arg_4, arg_9, arg_10, arg_11, arg_12));
		printf("---------------------------------------------------\n\n");
		printf("Test 2:\n");
		printf("printf %sArgs : %d | %i | %d | %i | %u | %u |\n", prompt_diu, arg_5, arg_6, arg_7, arg_8, arg_29, arg_30);
		printf("---------------------------------------------------\nft_printf :\n");
		printf("%d\n", ft_printf(prompt_diu, arg_5, arg_6, arg_7, arg_8, arg_29, arg_30));
		printf("---------------------------------------------------\n\nprintf :\n");
		printf("%d\n", printf(prompt_diu, arg_5, arg_6, arg_7, arg_8, arg_29, arg_30));
		printf("---------------------------------------------------\n");
/*		printf("Test 3:\n");
		printf("printf %s\n", prompt_per);
		printf("---------------------------------------------------\n\nft_printf :\n");
		printf("%d\n", ft_printf(prompt_per));
		printf("---------------------------------------------------\n\nprintf :\n");
		printf("%d\n", printf(prompt_per));
*/		printf("Test :4\n");
                printf("printf %sArgs : %x | %x | %X | %X \n", prompt_xX, arg_13, arg_14, arg_15, arg_16);
                printf("---------------------------------------------------\nft_printf :\n");
                printf("%d\n", ft_printf(prompt_xX, arg_13, arg_14, arg_15, arg_16));
                printf("---------------------------------------------------\n\nprintf :\n");
                printf("%d\n", printf(prompt_xX, arg_13, arg_14, arg_15, arg_16));
                printf("---------------------------------------------------\n\n");
                printf("Test :5\n");
                printf("printf %sArgs : %p | %p | %p | %p \n", prompt_p, arg_17, arg_18, arg_19, arg_20);
                printf("---------------------------------------------------\nft_printf :\n");
                printf("%d\n", ft_printf(prompt_p, arg_17, arg_18, arg_19, arg_20));
                printf("---------------------------------------------------\n\nprintf :\n");
                printf("%d\n", printf(prompt_p, arg_17, arg_18, arg_19, arg_20));
                printf("---------------------------------------------------\n\n");
                printf("Test args with : *\n");
                printf("printf %sArgs : %i | %i | %i | %s | %i | %i | %i | %c \n", prompt_args, arg_21, arg_22, arg_23, arg_24, arg_25, arg_26, arg_27, arg_28);
                printf("---------------------------------------------------\nft_printf :\n");
                printf("%d\n", ft_printf(prompt_args, arg_21, arg_22, arg_23, arg_24, arg_25, arg_26, arg_27, arg_28));
                printf("---------------------------------------------------\n\nprintf :\n");
                printf("%d\n", printf(prompt_args, arg_21, arg_22, arg_23, arg_24, arg_25, arg_26, arg_27, arg_28));
                printf("---------------------------------------------------\n\n");
                printf("Check overflow protection:\n");
                printf("ft_printf:\n");
		printf("%d\n", ft_printf(prompt_of, arg_5));
		printf("printf:\n");
		printf("%d\n", printf(prompt_of, arg_5));
		printf("ft_printf:\n");
		printf("%d\n", ft_printf(prompt_of_2, arg_5));
		printf("printf:\n");
		printf("%d\n", printf(prompt_of_2, arg_5));
		free(arg_18);
		free(arg_19);
		free(arg_20);
		return (0);
	}
}
