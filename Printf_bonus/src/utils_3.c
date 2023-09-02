
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
