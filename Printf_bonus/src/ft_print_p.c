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

static void	ft_get_hex(unsigned long int nb, char *str, char x)
{
	unsigned char		i;

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

char	*ft_itoa_base_long(unsigned long int nb, char x)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	res = ft_calloc(1, 13);
	if (!nb)
	{
		res[0] = '0';
		return (res);
	}
	j = 44;
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

int	ft_print_p(unsigned long adr, t_vars *vars)
{
	int		ret_val;
	int		len;
	int		i;
	char	*str;

	i = 0;
	ret_val = 0;
	if (!adr)
	{	
		str = ft_strdup("(nil)");
		len = 5;
	}
	else
	{
		str = ft_itoa_base_long(adr, 'x');
		len = ft_strlen(str) + 2;
	}
	if (adr && vars->field_width == ' ' && len < vars->nb_point)
	{
		while (i + vars->nb_point < vars->nb_field_width - 2)
		{
			i += write (1, " ", 1);
			ret_val++;
		}
	}
	else if (vars->field_width == ' ')
	{
		while (i + len < vars->nb_field_width)
		{
			i += write(1, " ", 1);
			ret_val++;
		}
	}
	i = 0;
	if (adr)
	{
		ret_val += ft_putstr("0x");
		i += 2;
	}
	if (vars->field_width == '0')
	{
		while (adr && i + len - 2 < vars->nb_field_width)
		{
			i += write(1, "0", 1);
			ret_val++;
		}
		while (!adr && i + len < vars->nb_field_width)
		{
			i += write(1, " ", 1);
                        ret_val++;
		}
	}
	else if (adr && vars->is_point == '.')
	{
		i = 0;
		while (i + len - 2 < vars->nb_point)
		{
			i += write(1, "0", 1);
			ret_val++;
		}
	}
	i += ft_putstr(str);
	if (adr)
	{
		i += 2;
		ret_val += len - 2;
	}
	else
		ret_val += len;
	if (vars->is_minus)
	{
		while (i < vars->nb_field_width_minus)
		{
			i += write(1, " ", 1);
			ret_val++;
		}
	}
	free(str);
	return (ret_val);
}
