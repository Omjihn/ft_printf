/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:52:48 by gbricot           #+#    #+#             */
/*   Updated: 2023/08/30 10:52:39 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_get_type(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && (ft_is_flag(str[i]) || ft_is_type(str[i])))
	{
		if (ft_is_type(str[i]))
		{
			if (str[i] == '%' && i > 1)
				return (0);
			return (str[i]);
		}
		i++;
	}
	return (0);
}

int	ft_field_width(const char *str, t_vars *vars)
{
	int	i;

	i = 0;
	if (str[i] == '0' || str[i] == '.')
		vars->field_width = '0';
	else if (ft_is_numeric(str[i]))
	{
		vars->field_width = ' ';
		i--;
	}
	i++;
	vars->nb_field_width = ft_atoi(str + i);
	while (str[i] && ft_is_numeric(str[i]))
		i++;
	return (i);
}

int	ft_str_limit(const char *str, t_vars *vars)
{
	int	i;

	vars->is_point = 1;
	vars->nb_point = ft_atoi(str + 1);
	i = 1;
	while (str[i] && ft_is_numeric(str[i]))
                i++;
	return (i);
}


int	ft_exec_before(char type, const char *str, t_vars *vars)
{
	int	i;
	
	i = 0;
	while (str[i] && str[i] != type)
	{
		if (str[i] == '+' && i == 0 && (type == 'd' || type == 'i'))
		{
			vars->is_plus = 1;
			i++;
		}
		else if (str[i] == ' ' && (type == 'd' || type == 'i'))
		{
			vars->is_space = 1;
			i++;
		}
		else if (str[i] == '#' && (type == 'x' || type == 'X'))
		{
			vars->is_ox = 1;
			i++;
		}
		else if (ft_is_numeric(str[i]) || (type != 's' && str[i] == '.'))
			i += ft_field_width(str + i, vars);
		else if (type == 's' && str[i] == '.')
			i += ft_str_limit(str + i, vars);
		//else if (str[i] == '-')
		else
			i++;
	}
	return (i);
}

int	ft_exec(t_vars *vars, va_list args, const char *str)
{
	char	type;

	(void) args;
	type = ft_get_type(str);
	printf("Type :%d\n", type);
	if (!type)
		return (1);
	vars->ret_val += ft_exec_before(type, str, vars);
	printf("is_error %d\nis_ox %d\nis_plus%d\nis_space%d\nis_point%d\nfield_width %d\nnb_field_width%d\nnb_point%d\nret_val%d\n", vars->is_error, vars->is_ox, vars->is_plus, vars->is_space, vars->is_point, vars->field_width, vars->nb_field_width, vars->nb_point, vars->ret_val);
	//vars->ret_val += ft_exec_cmd(type, str, args);
	//vars->ret_val += ft_exec_after(type, str);
	return (0);
}