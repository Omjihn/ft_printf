/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:46:03 by gbricot           #+#    #+#             */
/*   Updated: 2023/09/05 15:16:41 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*tmp_ptr;
	int		tmp_res;
	int		i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tmp_res = nmemb * size;
	if (tmp_res / size != nmemb)
		return (NULL);
	ptr = malloc(tmp_res);
	if (ptr == NULL)
		return (ptr);
	i = 0;
	tmp_ptr = ptr;
	while (i < tmp_res)
	{
		tmp_ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

static void	ft_get_hex(unsigned long int nb, char *str, char x)
{
	unsigned char		i;

	i = 1;
	while (i <= 8)
	{
		if (nb & i)
			str[0] += i;
		i <<= 1;
	}
	if (str[0] >= 0 && str[0] <= 9)
		str[0] += '0';
	else if (x == 'x')
		str[0] += 'a' - 10;
	else
		str[0] += 'A' - 10;
}

char	*ft_itoa_base_long(unsigned long int nb, char x)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	res = ft_calloc(1, 13);
	if (!nb)
	{
		res[0] = '0';
		return (res);
	}
	j = 44;
	while (j >= 0)
	{
		ft_get_hex(nb >> j, res + i, x);
		j -= 4;
		if (res[i] == '0' && !i)
			res[i] = 0;
		else
			i++;
	}
	return (res);
}
