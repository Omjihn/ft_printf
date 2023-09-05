/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:15:12 by gbricot           #+#    #+#             */
/*   Updated: 2023/09/04 09:47:11 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_2(const char *str, t_vars *vars, va_list args)
{
	int	i;

	i = 0;
	while (str[i] && !vars->is_error)
	{
		if (str[i] == '%')
			i += ft_exec(vars, args, str + i + 1) + 1;
		else
			vars->ret_val += write(1, str + i, 1);
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	int		ret_val;
	va_list	args;
	t_vars	*vars;

	if (!str)
		return (-1);
	vars = ft_calloc(sizeof(t_vars), 1);
	va_start(args, str);
	ft_printf_2(str, vars, args);
	va_end(args);
	ret_val = vars->ret_val;
	if (vars->is_error)
	{
		free(vars);
		return (-1);
	}
	free(vars);
	return (ret_val);
}
