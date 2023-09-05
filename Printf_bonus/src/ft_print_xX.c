/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:45:06 by gbricot           #+#    #+#             */
/*   Updated: 2023/09/04 14:59:10 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_get_hex(unsigned int nb, char *str, char x)
{
	unsigned int		i;

	i = 1;
	while (i <= 8)
	{
		if (nb & i)
			str[0] += i;
		i <<= 1;
	}
	if (str[0] >= 0 && str[0] <= 9)
		str[0] += '0';
	else if (x == 'x')
		str[0] += 'a' - 10;
	else
		str[0] += 'A' - 10;
}

char	*ft_itoa_base(unsigned int nb, char x)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	res = ft_calloc(1, 9);
	if (!nb)
	{
		res[0] = '0';
		return (res);
	}
	j = 28;
	while (j >= 0)
	{
		ft_get_hex(nb >> j, res + i, x);
		j -= 4;
		if (res[i] == '0' && !i)
			res[i] = 0;
		else
			i++;
	}
	return (res);
}

static int	ft_print_x_2(unsigned int nb, int ret_val, t_vars *vars)
{
	vars->str = ft_itoa_base(nb, vars->type);
	vars->len = ft_strlen(vars->str);
	ret_val = 0;
	if (vars->is_ox && nb)
		vars->sign = 2;
	vars->i = 0;
	if (vars->field_width == ' ' && vars->len < vars->nb_point)
	{
		while (vars->i + vars->nb_point < vars->nb_field_width - vars->sign)
		{
			vars->i += write(1, " ", 1);
			ret_val++;
		}
	}
	else if (vars->field_width == ' ')
	{
		while (vars->i + vars->len < vars->nb_field_width - vars->sign)
		{
			vars->i += write(1, " ", 1);
			ret_val++;
		}
	}
	vars->i = 0;
	return (ret_val);
}

static int	ft_print_x_3(int ret_val, t_vars *vars)
{
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
	return (ret_val);
}

int	ft_print_x(unsigned int nb, t_vars *vars)
{
	int		ret_val;

	ret_val = ft_print_x_2(nb, 0, vars);
	if (vars->is_ox && nb)
	{
		if (vars->type == 'X')
			ret_val += write(1, "0X", 2);
		else
			ret_val += write(1, "0x", 2);
		vars->i += 2;
	}
	ret_val = ft_print_x_3(ret_val, vars);
	ret_val += vars->len;
	vars->i += ft_putstr(vars->str);
	if (vars->is_minus)
	{
		while (vars->i < vars->nb_field_width_minus - vars->sign)
		{
			vars->i += write(1, " ", 1);
			ret_val++;
		}
	}
	free(vars->str);
	return (ret_val);
}
