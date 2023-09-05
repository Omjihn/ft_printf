/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:13:46 by gbricot           #+#    #+#             */
/*   Updated: 2023/09/05 13:54:53 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_di_2(int nb, int ret_val, t_vars *vars)
{
	if (nb < 0)
		vars->len--;
	vars->sign = 0;
	if (((vars->field_width || vars->is_point) && nb < 0) 
		|| (vars->is_plus && nb >= 0) || (vars->is_space && nb >= 0))
		vars->sign = -1;
	if (vars->field_width == ' ' && vars->len < vars->nb_point)
	{
		vars->i = vars->nb_point;
		while (vars->i < vars->nb_field_width + vars->sign)
		{
			vars->i += write(1, " ", 1);
			ret_val++;
		}
	}
	else if (vars->field_width == ' ')
	{
		vars->i = vars->len;
		while (vars->i < vars->nb_field_width + vars->sign)
		{
			vars->i += write(1, " ", 1);
			ret_val++;
		}
	}
	return (ret_val);
}

int	ft_print_di_3(int ret_val, char minus, t_vars *vars)
{
	if (vars->field_width == '0')
	{
		while (vars->i + vars->len < vars->nb_field_width + minus)
		{
			vars->i += write(1, "0", 1);
			ret_val++;
		}
	}
	else if (vars->is_point == '.')
	{
		while (vars->i + vars->len < vars->nb_point + minus)
		{
			vars->i += write(1, "0", 1);
			vars->ret_val++;
		}
	}
	return (ret_val);
}

int	ft_print_di_4(int ret_val, char minus, t_vars *vars)
{
	if (!vars->is_point || (vars->is_point && vars->nb_point > 0))
	{
		ret_val += ft_strlen(vars->str) - minus;
		vars->i += ft_putstr(vars->str + minus);
	}
	if (vars->is_minus)
	{
		while (vars->i < vars->nb_field_width_minus - minus + vars->sign)
		{
			vars->i += write(1, " ", 1);
			ret_val++;
		}
	}
	free(vars->str);
	return (ret_val);
}

int	ft_print_di(int nb, t_vars *vars)
{
	int		ret_val;
	char	minus;

	minus = 0;
	vars->str = ft_itoa(nb);
	vars->len = ft_strlen(vars->str);
	ret_val = ft_print_di_2(nb, 0, vars);
	vars->i = 0;
	if ((vars->field_width || vars->is_point) && nb < 0)
	{
		minus += write(1, "-", 1);
		vars->sign = 0;
		ret_val++;
	}
	else if (vars->is_plus)
		ret_val += write(1, "+", 1);
	else if (vars->is_space)
		ret_val += write(1, " ", 1);
	ret_val = ft_print_di_3(ret_val, minus, vars);
	ret_val = ft_print_di_4(ret_val, minus, vars);
	return (ret_val);
}
