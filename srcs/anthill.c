#include "../includes/lem_in.h"

t_anthill 		*create_room(char *line, int *start_end, int pos)
{
	t_anthill *new_node;
	int pos_scd;

	pos_scd = 0;
	new_node = (t_anthill *)ft_memalloc(sizeof(t_anthill));
	new_node->name = ft_strndup(line, 0, pos);
	pos_scd = ft_strchr(line+pos, ' ');
	new_node->cor[0] = ft_natoi(line+pos,pos);
	new_node->cor[1] = ft_atoi(line+pos+pos_scd);
	return (new_node);
}
void init_anthill(t_danthill **anthill, int ant_nb)
{
	(*anthill) = (t_danthill *)ft_memalloc(sizeof(t_danthill));
	(*anthill)->head = NULL;
	(*anthill)->tail = NULL;
	(*anthill)->ant_nb = ant_nb;
}

void free_anthill(t_danthill **anthill)
{
}

void save_room(t_anthill *new_node, t_danthill **anthill)
{
	if (new_node) {
		/*printf("cor_x->%d cor_y%d for->%s\n",new_node->cor[0],
		new_node->cor[1], new_node->name);*/
		if ((*anthill))
		{
			if (!(*anthill)->head && !(*anthill)->tail)
			{
				(*anthill)->hash_table[hash(new_node->name)] = new_node;
			}
			else
			{
				(*anthill)->tail->next = new_node;
				new_node->prev = (*anthill)->tail;
				(*anthill)->tail = new_node;
				new_node->next = NULL;
			}
		}
	}
}
