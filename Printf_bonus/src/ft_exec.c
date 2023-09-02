/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:52:48 by gbricot           #+#    #+#             */
/*   Updated: 2023/09/02 13:57:20 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_get_type(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && (ft_is_flag(str[i]) || ft_is_type(str[i])))
	{
		if (ft_is_type(str[i]))
		{
			if (str[i] == '%' && i > 1)
				return (0);
			return (str[i]);
		}
		i++;
	}
	return (0);
}

static void	ft_reset_vars(t_vars *vars)
{
	vars->type = 0;
	vars->is_ox = 0;
	vars->is_plus = 0;
	vars->is_space = 0;
	vars->is_point = 0;
	vars->field_width = 0;
	vars->nb_field_width = 0;
	vars->nb_point = 0;
	vars->is_minus = 0;
}

int	ft_exec_before(char type, const char *str, t_vars *vars)
{
	int	i;
	
	i = 0;
	while (str[i] && str[i] != type)
	{
		if (str[i] == '+' && i == 0 && (type == 'd' || type == 'i'))
		{
			vars->is_plus = 1;
			i++;
		}
		else if (str[i] == ' ' && (type == 'd' || type == 'i'))
		{
			vars->is_space = 1;
			i++;
		}
		else if (str[i] == '#' && (type == 'x' || type == 'X'))
		{
			vars->is_ox = 1;
			i++;
		}
		else if (ft_is_numeric(str[i]) || (type != 's' && str[i] == '.'))
			i += ft_field_width(str + i, vars);
		else if (type == 's' && str[i] == '.')
			i += ft_str_limit(str + i, vars);
		else if (str[i] == '-')
			i += ft_field_width_right(str + i, vars);
		else
			i++;
	}
	return (i);
}

int	ft_wich_type(va_list args, t_vars *vars)
{
	if (vars->type == 'c')
		return (ft_print_c(va_arg(args, int), vars));
	else if (vars->type == 's')
		return (ft_print_s(va_arg(args, char *), vars));
//	else if (vars->type == 'p')
//		return (ft_print_p(va_arg(args, unsigned long), vars));		
	else if (vars->type == 'd' || vars->type == 'i')
		ft_print_di(va_arg(args, int), vars);
/*	else if (vars->type == 'u')
		
	else if (vars->type == 'x')
		
	else if (vars->type == 'X')
		
	else if (vars->type == '%')
*/		
//	else
	return (0);
}

int	ft_exec(t_vars *vars, va_list args, const char *str)
{
	int		i;
	char	type;

	(void) args;
	type = ft_get_type(str);
	vars->type = type;
	//printf("Type :%d\n", type);
	if (!type)
		return (1);
	i = ft_exec_before(type, str, vars);
	//printf("is_error %d\nis_ox %d\nis_plus %d\nis_space %d\nis_point %d\nfield_width %d\nnb_field_width %d\nnb_point %d\nret_val %d\nis_minus %d\n", vars->is_error, vars->is_ox, vars->is_plus, vars->is_space, vars->is_point, vars->field_width, vars->nb_field_width, vars->nb_point, vars->ret_val, vars->is_minus);
	vars->ret_val += ft_wich_type(args, vars);
	ft_reset_vars(vars);
	return (i);
}
