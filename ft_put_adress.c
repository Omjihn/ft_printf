/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:15:42 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/06 18:28:41 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_adress(unsigned long adress)
{
	int	len;

	if (!adress)
		return (write (1, "(nil)", 5));
	len = write (1, "0x", 2);
	ft_putnbr_adress(adress);
	while (adress > 15)
	{
		adress /= 16;
		len++;
	}
	len++;
	return (len);
}

void	ft_putnbr_adress(unsigned long nb)
{
	if (nb < 16)
	{
		if (nb < 10)
		{
			nb += '0';
			write (1, &nb, 1);
		}
		else
		{
			nb += 'a' - 10;
			write (1, &nb, 1);
		}
	}
	else
	{
		ft_putnbr_adress(nb / 16);
		ft_putnbr_adress(nb % 16);
	}
}
