
#include "ft_printf.h"

static void	ft_get_hex(unsigned int nb, char *str, char x)
{
	unsigned int		i;

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

char	*ft_itoa_base(unsigned int nb, char x)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	res = ft_calloc(1, 9);
	if (!nb)
	{
		res[0] = '0';
		return (res);
	}
	j = 28;
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

int	ft_print_xX(unsigned int nb, t_vars *vars)
{
	int		ret_val;
	int		len;
	int		i;
	char	*str;

	str = ft_itoa_base(nb, vars->type);
	len = ft_strlen(str);
	ret_val = 0;
	i = 0;
	if (vars->is_ox && nb)
		i += 2;
	if (vars->field_width == ' ')
	{
		while (i + len < vars->nb_field_width)
		{
			i += write(1, " ", 1);
			ret_val++;
		}
	}
	if (vars->is_ox && nb)
	{
		if (vars->type == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
		ret_val += 2;
	}
	ret_val += len;
	i += ft_putstr(str);	
	free(str);
	return (ret_val);
}
