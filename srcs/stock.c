#include "../includes/lem_in.h"

static int				ft_natoi(const char *str, size_t cn)
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



t_anthill 		*stock_room(char *line, int *start_end, int pos)
{
	t_anthill *new_node;
	int pos_scd;

	pos_scd = 0;
	new_node = (t_anthill *)ft_memalloc(sizeof(t_anthill));
	new_node->name = ft_strndup(line, 0, pos);
	pos_scd = ft_strchr(line+pos, ' ');
	new_node->cor[0] = ft_natoi(line+pos, pos);
	new_node->cor[1] = ft_atoi(line+pos+pos_scd);
	return (new_node);
}
