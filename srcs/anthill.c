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
	ft_memset((*anthill)->hash_table, 0, MAX_ANTHILL);
}

void free_anthill(t_danthill **anthill)
{
}

void save_room(t_anthill *new_node, t_danthill **anthill)
{
	if (new_node) {
		if ((*anthill))
		{
			if (!(*anthill)->head && !(*anthill)->tail)
			{
				(*anthill)->hash_table[hash(new_node->name)] = new_node;
				(*anthill)->head = new_node;
				(*anthill)->tail = new_node;
			}
			else
			{
				(*anthill)->hash_table[hash(new_node->name)] = new_node;
				(*anthill)->tail->next = new_node;
				new_node->prev = (*anthill)->tail;
				(*anthill)->tail = new_node;
				new_node->next = NULL;
			}
		}
	}
}

void	pipe_creation(char *line, t_danthill **anthill)
{
	t_anthill	*frst_hill;
	t_anthill	*scd_hill;
	char		**splitresult;

	frst_hill = NULL;
	scd_hill = NULL;
	splitresult = NULL;

	splitresult = ft_strsplit(line, '-');
	printf("%s<-pipe->%s\n", splitresult[0], splitresult[1]);
	(*anthill)->hash_table[hash(splitresult[0])];
	hash(splitresult[0]);
	hash(splitresult[1]);
}
