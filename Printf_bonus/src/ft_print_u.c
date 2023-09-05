/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:53:58 by gbricot           #+#    #+#             */
/*   Updated: 2023/09/05 13:54:09 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nblen(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb || !len)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_unsigned(unsigned int nb)
{
	int		len;
	char	*res;

	len = ft_nblen(nb);
	res = ft_calloc(1, len + 1);
	while (nb || len)
	{
		res[--len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (res);
}

static int	ft_print_u_2(unsigned int nb, int ret_val, t_vars *vars)
{
	vars->str = ft_itoa_unsigned(nb);
	vars->len = ft_strlen(vars->str);
	vars->i = 0;
	if (vars->field_width == ' ' && vars->len < vars->nb_point)
	{
		vars->i = vars->nb_point;
		while (vars->i < vars->nb_field_width)
		{
			vars->i += write(1, " ", 1);
			ret_val++;
		}
	}
	else if (vars->field_width == ' ')
	{
		vars->i = vars->len;
		while (vars->i < vars->nb_field_width)
		{
			vars->i += write(1, " ", 1);
			ret_val++;
		}
	}
	vars->i = 0;
	return (ret_val);
}

static int	ft_print_u_3(int ret_val, t_vars *vars)
{
	ret_val += vars->len;
	vars->i += ft_putstr(vars->str);
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

int	ft_print_u(unsigned int nb, t_vars *vars)
{
	int		ret_val;

	ret_val = ft_print_u_2(nb, 0, vars);
	if (vars->field_width == '0')
	{
		while (vars->i + vars->len < vars->nb_field_width)
		{
			vars->i += write(1, "0", 1);
			ret_val++;
		}
	}
	else if (vars->is_point == '.')
	{
		vars->i = 0;
		while (vars->i + vars->len < vars->nb_point)
		{
			vars->i += write(1, "0", 1);
			ret_val++;
		}
	}
	ret_val = ft_print_u_3(ret_val, vars);
	return (ret_val);
}
