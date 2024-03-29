/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:16:43 by gbricot           #+#    #+#             */
/*   Updated: 2023/09/04 15:16:14 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_vars
{
	char	type;
	char	is_error;
	char	sign;
	char	is_wrong_flag;
	char	is_ox;
	char	is_plus;
	char	is_space;
	char	is_point;
	char	is_minus;
	char	field_width;
	char	*str;
	va_list	*args;
	int		i;
	int		len;
	int		nb_field_width;
	int		nb_field_width_minus;
	int		nb_point;
	int		ret_val;
}			t_vars;

int		ft_printf(const char *format, ...);
int		ft_exec(t_vars *vars, va_list args, const char *str);

/*		UTILS		*/

int		ft_is_type(char c);
int		ft_is_flag(char c);
int		ft_strlen(char *str);
int		ft_putstr(char *str);
int		ft_is_numeric(char c);
int		ft_atoi(const char *nptr, t_vars *vars);

char	ft_get_type(const char *str);

char	*ft_itoa(int n);
char	*ft_strdup(char *s);
char	*ft_itoa_base_long(unsigned long int nb, char x);

void	ft_reset_vars(t_vars *vars);

void	*ft_calloc(size_t nmemb, size_t size);

/*		FLAGS		*/

int		ft_str_limit(const char *str, t_vars *vars, va_list args);
int		ft_field_width(const char *str, t_vars *vars, va_list args);
int		ft_field_width_right(const char *str, t_vars *vars, va_list args);

/*		PRINT		*/

int		ft_print_c(char c, t_vars *vars);
int		ft_print_di(int nb, t_vars *vars);
int		ft_print_s(char *str, t_vars *vars);
int		ft_print_x(unsigned int nb, t_vars *vars);
int		ft_print_u(unsigned int nb, t_vars *vars);
int		ft_print_p(unsigned long int adr, t_vars *vars);

#endif
