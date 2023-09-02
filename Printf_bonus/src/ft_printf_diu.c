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

int	ft_print_diu(int nb, t_vars *vars)
{
	int		i;
	int		len;
	char	*str;

	str = ft_itoa(nb);
	len = ft_strlen(str);
	i = 0;
	if (vars->is_space && nb > 0 && !vars->is_plus)
	{
		vars->ret_val += write(1, " ", 1);
		i++;
	}
	else if (nb >= 0 && vars->is_plus)
	{
		vars->ret_val += write(1, "+", 1);
		i++;
	}
	else if ()
	
	free(str);
	return (i);
}
