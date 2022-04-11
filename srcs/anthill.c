#include "../includes/lem_in.h"

void free_room(t_danthill **anthill)
{
}


t_room 		*create_room(char *line, int *start_end, int pos)
{
	t_room *new_room;
	int pos_scd;

	pos_scd = 0;
	new_room = (t_room *)ft_memalloc(sizeof(t_room));
	new_room->name = ft_strndup(line, 0, pos - 1);
	pos_scd = ft_strchr(line+pos, ' ');
	new_room->cor[0] = ft_natoi(line+pos,pos);
	new_room->cor[1] = ft_atoi(line+pos+pos_scd);
	return (new_room);
}
void init_anthill(t_danthill **anthill, int ant_nb)
{
	(*anthill) = (t_danthill *)ft_memalloc(sizeof(t_danthill));
	(*anthill)->head = NULL;
	(*anthill)->tail = NULL;
	(*anthill)->ant_nb = ant_nb;
	(*anthill)->lock_start_end = 0;
	ft_memset((*anthill)->hash_table, 0, MAX_ROOM);
}

t_piperoom	*init_pipe(t_room *new_room)
{
	t_piperoom	*pipe_room;

	pipe_room = (t_piperoom *)ft_memalloc(sizeof(t_piperoom));
	pipe_room->room = new_room;
	pipe_room->next = NULL;
	return (pipe_room);
}

void save_room(t_room *new_room, t_danthill **anthill)
{
	t_piperoom *pipe_room;

	pipe_room = NULL;
	if (new_room) {
		pipe_room = init_pipe(new_room);
		if ((*anthill))
		{
			if (!(*anthill)->head && !(*anthill)->tail)
			{
				(*anthill)->hash_table[hash(new_room->name)] = pipe_room;
				(*anthill)->head = new_room;
				(*anthill)->tail = new_room;
				if ((*anthill)->lock_start_end == START) {
					(*anthill)->start = new_room;
					(*anthill)->lock_start_end= 0;
				}
				if ((*anthill)->lock_start_end == END) {
					(*anthill)->start = new_room;
					(*anthill)->lock_start_end= 0;
				}
			}
			else
			{
				(*anthill)->hash_table[hash(new_room->name)] = pipe_room;
				(*anthill)->tail->next = new_room;
				new_room->prev = (*anthill)->tail;
				(*anthill)->tail = new_room;
				new_room->next = NULL;
				if ((*anthill)->lock_start_end == START) {
					(*anthill)->start = new_room;
					(*anthill)->lock_start_end= 0;
				}
				if ((*anthill)->lock_start_end == END) {
					(*anthill)->start = new_room;
					(*anthill)->lock_start_end= 0;
				}
			}

		}
	}
}

void	pipe_creation(char *line, t_danthill **anthill)
{
	t_piperoom	*tmp;
	t_piperoom	*new_pipe;
	char		**splitresult;

	tmp = NULL;
	new_pipe = NULL;
	splitresult = ft_strsplit(line, '-');
	if ((*anthill)->hash_table[hash(splitresult[0])] &&
		(*anthill)->hash_table[hash(splitresult[1])])
		{
			if ((*anthill)->hash_table[hash(splitresult[0])])
			{
				new_pipe = init_pipe((*anthill)->hash_table[hash(splitresult[1])]->room);
				tmp = (*anthill)->hash_table[hash(splitresult[0])];
				if (!tmp->next)
					tmp->next = new_pipe;
				else
				{
					while (tmp->next)
						tmp = tmp->next;
					tmp->next = new_pipe;
				}

			}
	}
}
