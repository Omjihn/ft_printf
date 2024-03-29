/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:52:48 by gbricot           #+#    #+#             */
/*   Updated: 2023/09/05 09:22:32 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_exec_before_2(char type, const char *str, int i, t_vars *vars)
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
	return (i);
}

int	ft_exec_before(char type, const char *str, t_vars *vars, va_list args)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != type)
	{
		i = ft_exec_before_2(type, str, i, vars);
		if (ft_is_numeric(str[i]) || str[i] == '*'
			|| (type != 's' && str[i] == '.'))
			i += ft_field_width(str + i, vars, args);
		else if (type == 's' && str[i] == '.')
			i += ft_str_limit(str + i, vars, args);
		else if (str[i] == '-')
		{
			if ((vars->field_width && vars->type != 'c') || vars->is_point)
			{
				vars->is_wrong_flag = 1;
				return (0);
			}
			i += ft_field_width_right(str + i, vars, args);
		}
		else
			i++;
	}
	return (i);
}

int	ft_print_percent(t_vars *vars, const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%' && (ft_is_numeric(str[i])
			|| ft_is_type(str[i]) || ft_is_flag(str[i])))
		i++;
	if (!str[i])
	{
		vars->is_error = 1;
		return (0);
	}
	else if (str[i] == '%')
		return (write(1, "%", 1));
	i = 0;
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int	ft_wich_type(va_list args, t_vars *vars, const char *str)
{
	if (vars->type == 'c')
		return (ft_print_c(va_arg(args, int), vars));
	else if (vars->type == 's')
		return (ft_print_s(va_arg(args, char *), vars));
	else if (vars->type == 'p')
		return (ft_print_p(va_arg(args, unsigned long int), vars));
	else if (vars->type == 'd' || vars->type == 'i')
		return (ft_print_di(va_arg(args, int), vars));
	else if (vars->type == 'u')
		return (ft_print_u(va_arg(args, unsigned int), vars));
	else if (vars->type == 'x' || vars->type == 'X')
		return (ft_print_x(va_arg(args, unsigned int), vars));
	else if (vars->type == '%')
		return (ft_print_percent(vars, str));
	return (0);
}

int	ft_exec(t_vars *vars, va_list args, const char *str)
{
	int		i;
	char	type;

	(void) args;
	type = ft_get_type(str);
	vars->type = type;
	if (!type)
		return (1);
	i = ft_exec_before(type, str, vars, args);
	if (vars->is_error)
		return (0);
	if (vars->is_wrong_flag == 1)
	{
		vars->ret_val += write(1, "%", 1);
		while (str[i] != type)
			i += write(1, &str[i], 1);
		i += write(1, &str[i], 1);
		ft_reset_vars(vars);
		vars->ret_val += i;
		return (i - 1);
	}
	vars->ret_val += ft_wich_type(args, vars, str);
	ft_reset_vars(vars);
	return (i);
}
