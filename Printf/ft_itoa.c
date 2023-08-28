/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:55:12 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/06 15:22:48 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_cnt_len(long int n)
{
	long long int	div;
	int				i;

	i = 0;
	div = 1;
	if (n <= 0)
	{
		i++;
		div *= -1;
	}
	while (n / div > 0)
	{
		div *= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr_str(long int n, char *res, int len)
{
	len--;
	if (n >= 10)
	{
		res[len] = (n % 10) + 48;
		len--;
	}
	else if (n < 10)
		res[len] = n + 48;
	while (n >= 10)
	{
		n /= 10;
		res[len] = (n % 10) + 48;
		len--;
	}
}

char	*ft_itoa(long int n)
{
	int			len;
	char		*res;

	len = ft_cnt_len(n);
	res = (char *) malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	ft_putnbr_str(n, res, len);
	res[len] = '\0';
	return (res);
}
