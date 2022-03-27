#include "../includes/lem_in.h"

int				prw(int base, int exp)
{
	int res=1;

	while(exp>=1)
	{
		res*=base;
		exp--;
	}
	return(res);
}

int				ft_natoi(const char *str, size_t cn)
{
	int		i;
	int		n;
	int		boolean;

	i = 0;
	n = 0;
	boolean = -1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			boolean = -boolean;
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && i < cn)
	{
		n = (10 * n - (str[i] - 48));
		i++;
	}
	return (n * boolean);
}

int			hash(char *item)
{
	int		p = 93;
	long long hash_value = 0;
	long long p_pow = 1;
	while (*item)
		item++;
	ft_putstr(" hash_item->");
	ft_putnbr(hash_item);
	ft_putchar('\n');
	return (index);
}
