/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:29:30 by gbricot           #+#    #+#             */
/*   Updated: 2023/09/05 14:31:40 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_interpret_dot(const char *str, int i, t_vars *vars, va_list args)
{
	if (vars->field_width == '0'
		&& ft_atoi(str + i + 1, vars) < vars->nb_field_width)
		vars->field_width = ' ';
	else if (vars->field_width == '0' && vars->type != 'c' && vars->type != 's')
		vars->field_width = 0;
	vars->is_point = '.';
	if (ft_is_numeric(str[i + 1]))
		vars->nb_point = ft_atoi(str + i + 1, vars);
	else if (str[i + 1] == '*')
		vars->nb_point = va_arg(args, int);
	else
		vars->is_wrong_flag = 2;
}

static void	ft_interpret_zero(const char *str, int i, t_vars *vars, \
	va_list args)
{
	vars->field_width = '0';
	if (ft_is_numeric(str[i + 1]))
		vars->nb_field_width = ft_atoi(str + i + 1, vars);
	else if (str[i + 1] == '*')
		vars->nb_field_width = va_arg(args, int);
	else
		vars->is_wrong_flag = 2;
}

static int	ft_wich_char(const char *str, int i, t_vars *vars, va_list args)
{
	if (str[i] == '0')
		ft_interpret_zero(str, i, vars, args);
	else if (str[i] == '.')
		ft_interpret_dot(str, i, vars, args);
	else if (ft_is_numeric(str[i]) || str[i] == '*')
	{
		vars->field_width = ' ';
		if (ft_is_numeric(str[i]))
			vars->nb_field_width = ft_atoi(str + i, vars);
		else if (str[i] == '*')
			vars->nb_field_width = va_arg(args, int);
		else
			vars->is_wrong_flag = 2;
		i--;
	}
	return (i);
}

int	ft_field_width(const char *str, t_vars *vars, va_list args)
{
	int	i;

	i = 0;
	if (vars->is_minus && vars->type != 'd' && vars->type != 'i'
		&& vars->type != 'u' && vars->type != 'x' && vars->type != 'X'
		&& vars->type != 'p')
	{
		while (str[i] && (ft_is_numeric(str[i])
				|| str[i] == '-' || str[i] == '*' || str[i] == '.'))
			i++;
		return (i);
	}
	i = ft_wich_char(str, i, vars, args);
	i++;
	while (str[i] && (ft_is_numeric(str[i]) || str[i] == '*'))
		i++;
	return (i);
}
