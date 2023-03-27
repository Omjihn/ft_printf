/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:40:25 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/05 16:14:06 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int nb)
{
	char	*res;
	int		size;

	res = ft_itoa(nb);
	size = ft_putstr(res);
	free(res);
	return (size);
}
