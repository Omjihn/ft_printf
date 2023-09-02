/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:15:12 by gbricot           #+#    #+#             */
/*   Updated: 2023/08/29 11:13:21 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret_val;
	va_list	args;
	t_vars	*vars;

	vars = ft_calloc(sizeof(t_vars), 1);
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i += ft_exec(vars, args, str + i + 1) + 1;
		else
			vars->ret_val += write(1, str + i, 1);
		i++;
	}
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
