/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:36:51 by gbricot           #+#    #+#             */
/*   Updated: 2023/03/06 18:27:32 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
int		wich_percent(const char *s, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long int nb);
int		ft_putnbr_hex(unsigned int nb, int x);
int		put_adress(unsigned long adress);
void	ft_putnbr_base(unsigned int nb, int x);
void	ft_putnbr_adress(unsigned long nb);
char	*ft_itoa(long int n);

#endif
