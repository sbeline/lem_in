#include "../includes/lem_in.h"

static int				*find_coor_xy(char *line)
{
	int		c[2];
	int		lock;

	lock = 0;
	while (*line)
	{
		if (*line == ' ')
			lock = 1;
		if (!lock && *line != ' ')
		{
			c[1] = ft_atoi((const char*)line) * 10;
		}
		if (lock && *line != ' ')
		{
			c[1] = ft_atoi((const char*)line) * 10;
		}
		line++;
	}
}



t_danthill 		*stock_room(char *line, int *start_end, int pos)
{
	t_danthill *new_node;

	new_node = (t_danthill *)ft_memalloc(sizeof(t_danthill));
	new_node->name = ft_strndup(line, 0, pos);

	new_node->coor = find_coor_xy(line+pos);;

	return (new_node);
}
