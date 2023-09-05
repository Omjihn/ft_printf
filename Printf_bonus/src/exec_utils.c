/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:16:55 by gbricot           #+#    #+#             */
/*   Updated: 2023/09/05 15:17:41 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_get_type(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && (ft_is_flag(str[i]) || ft_is_type(str[i])))
	{
		if (ft_is_type(str[i]))
			return (str[i]);
		i++;
	}
	if (!str[i])
		return (0);
	else
		return ('%');
}

void	ft_reset_vars(t_vars *vars)
{
	vars->i = 0;
	vars->len = 0;
	vars->type = 0;
	vars->sign = 0;
	vars->is_ox = 0;
	vars->str = NULL;
	vars->is_plus = 0;
	vars->is_space = 0;
	vars->is_point = 0;
	vars->nb_point = 0;
	vars->is_minus = 0;
	vars->field_width = 0;
	vars->is_wrong_flag = 0;
	vars->nb_field_width = 0;
	vars->nb_field_width_minus = 0;
}
