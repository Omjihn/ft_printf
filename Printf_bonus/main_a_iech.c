
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "gnl/get_next_line_bonus.h"
#include "src/ft_printf.h"

#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define WHT "\033[0;37m"

int	main(int ac, char **av)
{
	char *prompt_cs = "%c | %s | % .6s | %.24s \n";
	char	arg_1 = 's';
	char	*arg_2 = "Oulala";
	char	*arg_3 = NULL;
	char	*arg_4 = "ljkeyg erkljuhbaoirufghb oeiabnf oekrjuhnagoiash g";
	
	
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
			printf("%d", ft_printf(prompt_cs, arg_1, arg_2, arg_3, arg_4));
			exit(0);
		}
		int pid_2 = fork();
		if (pid_2 == 0)
		{
			dup2(fd[1][1], STDOUT_FILENO);
			close(fd[1][0]);
			close(fd[1][1]);
			printf("%d", printf(prompt_cs, arg_1, arg_2, arg_3, arg_4));
			exit(0);
		}
		close(fd[0][1]);
		close(fd[1][1]);
		waitpid(pid_1, NULL, 0);
		waitpid(pid_2, NULL, 0);
		char *res_1 = get_next_line(fd[0][0]);
		char *res_2 = get_next_line(fd[1][0]);
		while (1)
		{
			if (res_1)
				free(res_1);
			if (res_2)
				free(res_2);
			res_1 = get_next_line(fd[0][0]);
			res_2 = get_next_line(fd[1][0]);
			if (res_1 && res_2 && strcmp(res_1, res_2))
			{
				printf(RED"FAIL\n"WHT);
				free(res_1);
				free(res_2);
				exit(0);
			}
			else if ((!res_1 && res_2) || !res_2 && res_1)
			{
				printf(RED"FAIL\n"WHT);
				if (res_1)
					free(res_1);
				if (res_2)
					free(res_2);
				exit(0);
			}
			else if (!res_1 && !res_2)
			{
				printf(GRN"SUCCESS\n"WHT);
				exit(0);
			}
		}
	}
	else
	{
		printf("printf %sArgs : %c, %s, %s, %s\n", prompt_cs, arg_1, arg_2, arg_3, arg_4);
		printf("---------------------------------------------------\n\nft_printf :\n");
		printf("%d\n", ft_printf(prompt_cs, arg_1, arg_2, arg_3, arg_4));
		printf("---------------------------------------------------\n\nprintf :\n");
		printf("%d\n", printf(prompt_cs, arg_1, arg_2, arg_3, arg_4));
		printf("---------------------------------------------------\n");
	}
}
