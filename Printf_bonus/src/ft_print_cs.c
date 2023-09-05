/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:59:12 by gbricot           #+#    #+#             */
/*   Updated: 2023/09/02 13:59:55 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char c, t_vars *vars)
{
	int	i;

	i = 1;
	if (vars->field_width)
		while (i < vars->nb_field_width)
			i += write(1, " ", 1);
	write(1, &c, 1);
	if (vars->is_minus)
	{
		while (i < vars->nb_field_width_minus)
			i += write(1, " ", 1);
	}
	return (i);
}

static int	ft_print_s_2(char *str, int ret_val, t_vars *vars)
{
	if (vars->field_width)
	{
		while (vars->i < vars->nb_field_width)
		{
			vars->i += write(1, " ", 1);
			ret_val++;
		}
	}
	vars->i = 0;
	while (str && vars->i < vars->len)
	{
		vars->i += write(1, &str[vars->i], 1);
		ret_val++;
	}
	if (vars->is_minus)
	{
		while (vars->i < vars->nb_field_width_minus)
		{
			vars->i += write(1, " ", 1);
			ret_val++;
		}
	}
	return (ret_val);
}

int	ft_print_s(char *str, t_vars *vars)
{
	int		ret_val;

	if (!str)
	{
		if ((vars->is_point && vars->nb_point >= 6) || !vars->is_point)
			return (ft_print_s("(null)", vars));
		else
			return (ft_print_s("", vars));
	}
	ret_val = 0;
	vars->len = 0;
	vars->len = ft_strlen(str);
	if (vars->nb_point)
		if (vars->nb_point < vars->len)
			vars->len = vars->nb_point;
	vars->i = vars->len;
	ret_val = ft_print_s_2(str, ret_val, vars);
	return (ret_val);
}
