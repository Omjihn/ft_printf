/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:13:46 by gbricot           #+#    #+#             */
/*   Updated: 2023/09/02 17:20:00 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_di(int nb, t_vars *vars)
{
	int		ret_val;
	int		i;
	int		len;
	char	*str;
	char	minus;

	ret_val = 0;
	minus = 0;
	str = ft_itoa(nb);
	len = ft_strlen(str);
	i = 0;
	if (vars->field_width == ' ')
	{
		i = len;
		while (i < vars->nb_field_width)
		{
			i += write(1, " ", 1);
			ret_val++;
		}
	}
	if ((vars->field_width || vars->is_point) && nb < 0)
	{
		minus += write(1, "-", 1);
		ret_val++;
	}
	else if (vars->is_plus && nb >= 0)
	{
		ret_val += write(1, "+", 1);
		//i++;
	}
	else if (vars->is_space && nb >= 0)
	{
		ret_val += write(1, " ", 1);
		//i++;
	}
	if (vars->field_width == '0')
	{
		while (i + len < vars->nb_field_width + minus)
		{
			i += write(1, "0", 1);
			ret_val++;
		}
	}
	else if (vars->is_point == '.')
	{
		while (i + len < vars->nb_point + minus)
		{
			i += write(1, "0", 1);
			vars->ret_val++;
		}
	}
	ret_val += ft_strlen(str) - minus;
	i += ft_putstr(str + minus);
	if (vars->is_minus)
	{
		while (i < vars->nb_field_width_minus - minus)
		{
			i += write(1, " ", 1);
			ret_val++;
		}
	}
	free(str);
	return (ret_val);
}
