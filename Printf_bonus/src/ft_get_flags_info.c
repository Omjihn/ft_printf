/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:04:38 by gbricot           #+#    #+#             */
/*   Updated: 2023/09/02 14:06:17 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_field_width_right(const char *str, t_vars *vars, va_list args)
{
	int	i;

	i = 0;
	if (vars->field_width && vars->type != 'd' && vars->type != 'i'
		&& vars->type != 'u')
	{
		while (str[i] && (ft_is_numeric(str[i])
				|| str[i] == ' ' || str[i] == '*'))
			i++;
		return (i);
	}
	i++;
	vars->is_minus = '-';
	if (ft_is_numeric(str[i]))
		vars->nb_field_width_minus = ft_atoi(str + i, vars);
	else if (str[i] == '*')
		vars->nb_field_width_minus = va_arg(args, int);
	else
		vars->is_wrong_flag = 2;
	while (str[i] && (ft_is_numeric(str[i]) || str[i] == '*'))
		i++;
	return (i);
}

int	ft_str_limit(const char *str, t_vars *vars, va_list args)
{
	int	i;

	vars->is_point = '.';
	if (ft_is_numeric(str[1]))
		vars->nb_point = ft_atoi(str + 1, vars);
	else if (str[1] == '*')
		vars->nb_point = va_arg(args, int);
	else
		vars->is_wrong_flag = 2;
	i = 1;
	while (str[i] && (ft_is_numeric(str[i]) || str[i] == '*'))
		i++;
	return (i);
}
