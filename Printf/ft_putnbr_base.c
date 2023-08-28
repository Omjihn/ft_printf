/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:31:12 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/07 17:55:50 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nb, int x)
{
	int	len;

	ft_putnbr_base(nb, x);
	len = 0;
	while (nb > 15)
	{
		nb /= 16;
		len++;
	}
	len++;
	return (len);
}

void	ft_putnbr_base(unsigned int nb, int x)
{
	if (nb < 16)
	{
		if (nb < 10)
		{
			nb += '0';
			write (1, &nb, 1);
		}
		else if (x == 'x')
		{
			nb += 'a' - 10;
			write (1, &nb, 1);
		}
		else
		{
			nb += 'A' - 10;
			write (1, &nb, 1);
		}
	}
	else
	{
		ft_putnbr_base(nb / 16, x);
		ft_putnbr_base(nb % 16, x);
	}
}
