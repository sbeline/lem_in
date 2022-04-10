#include "../includes/lem_in.h"

void 			print_room(t_danthill *anthill)
{
	t_room	*ptr;
	int len = 0;
	t_piperoom *tmp;

	ptr = anthill->head;
	int	count_ar= 0;
	int count_et = 0;
	ptr = NULL;
	tmp = NULL;

	while (len < MAX_ROOM)
	{
		if (anthill->hash_table[len]) {
				printf("index->%d name->%s\n", len, anthill->hash_table[len]->room->name);
			// list of pipe .
			tmp = anthill->hash_table[len];
			if (tmp)
				printf("list of pipe:\n");
			while (tmp) {
				//code
				printf("->%s\n", tmp->room->name);
				tmp = tmp->next;
			}
			count_ar++;
		}
		len++;
	}
	ptr = anthill->head;
	while (ptr) {
		printf("cor_x->%d cor_y%d for->%s\n", ptr->cor[0],
		ptr->cor[1], ptr->name);
		ptr = ptr->next;
		count_et++;
	}
	printf("START->%s END->%s \n", anthill->start->name, anthill->end->name);
	printf("ar entry:%d  et entry:%d\n", count_ar, count_et);
}



t_danthill		*parser_lexer()
{
	t_danthill	*anthill;
	char 		*buf;
	int			er;

	er = 0;
	anthill = NULL;
	while ((get_next_line(0, &buf)) > 0)
	{
		if (!anthill && !ft_isdigit(ft_atoi(buf)))
			init_anthill(&anthill, ft_atoi(buf));
		if (!anthill)
			return (er_in_map(-1, &anthill));
		if (find_line_type(buf, &anthill) < 0)
			return (er_in_map(er, &anthill));
	}
	return (anthill);
}

int main(int ac, char **av)
{
	t_danthill	*anthill;

	anthill = NULL;
	//parser_files() #function to create le
	anthill = parser_lexer();
	if (anthill) {
		/* function for print*/
		print_room(anthill);

		// part of program to resolv problem

		edk_algo(anthill);

	}
    return (0);
}
