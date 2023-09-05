/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:32:31 by gbricot           #+#    #+#             */
/*   Updated: 2023/08/29 12:05:49 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+' 
		|| c == '.' || ft_is_numeric(c) || c == '*')
		return (1);
	return (0);
}

static int	ft_will_of(int total, int sign, int add)
{
	int	temp;

	if (total == 0 && add == 0)
		return (0);
	temp = (total * 10) + add;
	if (sign > 0)
	{
		if ((temp - add) / 10 == total && temp > 0)
			return (0);
		else
			return (1);
	}
	temp *= -1;
	if ((temp + add) / 10 == total * -1 && temp < 0)
		return (0);
	else
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr, t_vars *vars)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (ft_will_of(result, sign, nptr[i] - 48) == 1)
			vars->is_error = 1;
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	return (result * sign);
}
