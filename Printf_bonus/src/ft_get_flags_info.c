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

int	ft_field_width_right(const char *str, t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->field_width && vars->type != 'd' && vars->type != 'i' && vars->type != 'u')
	{
		while (str[i] && (ft_is_numeric(str[i])
				|| str[i] == ' ' || str[i] == '*'))
			i++;
		return (i);
	}
	i++;
	vars->is_minus = '-';
	if (ft_is_numeric(str[i]))
		vars->nb_field_width_minus = ft_atoi(str + i);
	else
		vars->is_wrong_flag = 2;
	while (str[i] && ft_is_numeric(str[i]))
		i++;
	return (i);
}

int	ft_field_width(const char *str, t_vars *vars)
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
	if (str[i] == '0')
	{
		vars->field_width = '0';
		if (ft_is_numeric(str[i + 1]))
			vars->nb_field_width = ft_atoi(str + i + 1);
		else
			vars->is_wrong_flag = 2;
	}
	else if (str[i] == '.')
	{	
		if (vars->field_width == '0' && ft_atoi(str + i + 1) < vars->nb_field_width)
			vars->field_width = ' ';
		else if (vars->field_width == '0' && vars->type != 'c' && vars->type != 's')
			vars->field_width = 0;
		vars->is_point = '.';
		if (ft_is_numeric(str[i + 1]))
			vars->nb_point = ft_atoi(str + i + 1);
		else
			vars->is_wrong_flag = 2;
	}	
	else if (ft_is_numeric(str[i]))
	{
		vars->field_width = ' ';
		if (ft_is_numeric(str[i]))
			vars->nb_field_width = ft_atoi(str + i);
		else
			vars->is_wrong_flag = 2;
		i--;
	}
	i++;
	while (str[i] && ft_is_numeric(str[i]))
		i++;
	return (i);
}

int	ft_str_limit(const char *str, t_vars *vars)
{
	int	i;

	vars->is_point = '.';
	if (ft_is_numeric(str[1]))
		vars->nb_point = ft_atoi(str + 1);
	else
		vars->is_wrong_flag = 2;
	i = 1;
	while (str[i] && ft_is_numeric(str[i]))
		i++;
	return (i);
}
