#include "../includes/lem_in.h"

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
	int		index;
	int		hash_item;

	index = 0;
	hash_item = 0;
	while (*item) {
		hash_item = hash_item ^ (int)*item;
		ft_putnbr(*item);
		ft_putstr(" hash_item->");
		ft_putnbr(hash_item);
		ft_putstr(" index->");
		ft_putnbr(index);
		ft_putchar('\n');
		item++;
	}

	index = hash_item % MAX_ANTHILL;

	return (index);
}
