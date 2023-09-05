/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:45:04 by gbricot           #+#    #+#             */
/*   Updated: 2023/09/04 17:09:35 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_p_2(unsigned long adr, int ret_val, t_vars *vars)
{
	if (adr && vars->field_width == ' ' && vars->len < vars->nb_point)
	{
		while (vars->i + vars->nb_point < vars->nb_field_width - 2)
		{
			vars->i += write (1, " ", 1);
			ret_val++;
		}
	}
	else if (vars->field_width == ' ')
	{
		while (vars->i + vars->len < vars->nb_field_width)
		{
			vars->i += write(1, " ", 1);
			ret_val++;
		}
	}
	vars->i = 0;
	return (ret_val);
}

static int	ft_print_p_3(unsigned long adr, int ret_val, t_vars *vars)
{
	if (vars->field_width == '0')
	{
		while (adr && vars->i + vars->len - 2 < vars->nb_field_width)
		{
			vars->i += write(1, "0", 1);
			ret_val++;
		}
		while (!adr && vars->i + vars->len < vars->nb_field_width)
		{
			vars->i += write(1, " ", 1);
			ret_val++;
		}
	}
	else if (adr && vars->is_point == '.')
	{
		vars->i = 0;
		while (vars->i + vars->len - 2 < vars->nb_point)
		{
			vars->i += write(1, "0", 1);
			ret_val++;
		}
	}
	vars->i += ft_putstr(vars->str);
	return (ret_val);
}

static int	ft_print_p_4(unsigned long adr, int ret_val, t_vars *vars)
{
	if (adr)
	{
		vars->i += 2;
		ret_val += vars->len - 2;
	}
	else
		ret_val += vars->len;
	if (vars->is_minus)
	{
		while (vars->i < vars->nb_field_width_minus)
		{
			vars->i += write(1, " ", 1);
			ret_val++;
		}
	}
	free(vars->str);
	return (ret_val);
}

int	ft_print_p(unsigned long adr, t_vars *vars)
{
	int		ret_val;

	vars->i = 0;
	if (!adr)
	{
		vars->str = ft_strdup("(nil)");
		vars->len = 5;
	}
	else
	{
		vars->str = ft_itoa_base_long(adr, 'x');
		vars->len = ft_strlen(vars->str) + 2;
	}
	ret_val = ft_print_p_2(adr, 0, vars);
	if (adr)
	{
		ret_val += ft_putstr("0x");
		vars->i += 2;
	}
	ret_val = ft_print_p_3(adr, ret_val, vars);
	ret_val = ft_print_p_4(adr, ret_val, vars);
	return (ret_val);
}
