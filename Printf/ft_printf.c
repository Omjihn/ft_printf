/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:39:22 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/09 13:37:01 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			i;
	int			ret_value;

	va_start(args, s);
	i = 0;
	ret_value = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
				return (-1);
			ret_value += wich_percent(s + i, args);
			i++;
		}
		else
			ret_value += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (ret_value);
}

int	wich_percent(const char *s, va_list args)
{
	if (s[1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (s[1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s[1] == 'p')
		return (put_adress(va_arg(args, unsigned long)));
	else if (s[1] == 'd' || s[1] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (s[1] == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (s[1] == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 'x'));
	else if (s[1] == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 'X'));
	else if (s[1] == '%')
		return (ft_putchar('%'));
	return (0);
}
