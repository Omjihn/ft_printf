/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:16:43 by gbricot           #+#    #+#             */
/*   Updated: 2023/08/30 09:35:22 by gbricot          ###   ########.fr       */
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
	char	is_error;
	char	is_ox;
	char	is_plus;
	char	is_space;
	char	is_point;
	char	field_width;
	int		nb_field_width;
	int		nb_point;
	int		ret_val;
}			t_vars;

/*		UTILS		*/

int		ft_printf(const char *format, ...);

int		ft_is_numeric(char c);
int		ft_is_type(char c);
int		ft_is_flag(char c);
int		ft_atoi(const char *nptr);



void	*ft_calloc(size_t nmemb, size_t size);

int	ft_exec(t_vars *vars, va_list args, const char *str);

#endif
