/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:03:01 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/13 17:10:38 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("%i\n", printf("%c, %s, %d, %i, %p, %x, %X, %u", 48, "oui\0non", 42, -42, (void *) 852, -42, 42, 123));
	ft_printf("%i\n", ft_printf("%c, %s, %d, %i, %p, %x, %X, %u", 48, "oui\0non", 42, -42, (void *) 852, -42, 42, 123));

	printf("%i\n", printf("%x, %X, %x, %X, %u, %d", INT_MAX, INT_MAX, INT_MIN, INT_MIN, INT_MIN, INT_MIN));
	ft_printf("%i\n", ft_printf("%x, %X, %x, %X, %u, %d", INT_MAX, INT_MAX, INT_MIN, INT_MIN, INT_MIN, INT_MIN));
}
