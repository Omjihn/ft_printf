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

int	ft_print_s(char *str, t_vars *vars)
{
	int		i;
	int		len;
	int		ret_val;

	if (!str)
	{	
		if ((vars->is_point && vars->nb_point >= 6) || !vars->is_point)
			return (ft_print_s("(null)", vars));
		else
			return (ft_print_s("", vars));
	}
	ret_val = 0;
	len = 0;
	len = ft_strlen(str);
	if (vars->nb_point)
		if (vars->nb_point < len)
			len = vars->nb_point;
	i = len;
	if (vars->field_width)
	{
		while (i < vars->nb_field_width)
		{
			i += write(1, " ", 1);
			ret_val++;
		}
	}
	i = 0;
	while (str && i < len)
	{
		i += write(1, &str[i], 1);
		ret_val++;
	}
	if (vars->is_minus)
	{
		while (i < vars->nb_field_width_minus)
		{
			i += write(1, " ", 1);
			ret_val++;
		}
	}
	return (ret_val);
}
