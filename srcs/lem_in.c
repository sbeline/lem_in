#include "../includes/lem_in.h"


void 			print_anthill(t_danthill *anthill)
{
	t_anthill	*ptr;
	int			hash_i = 0;

	ptr = anthill->head;
	while (ptr) {
		/* code */
		hash_i = hash(ptr->name);
		printf("cor_x->%d cor_y%d for->%s hash->%d\n", ptr->cor[0],
		ptr->cor[1], ptr->name, hash_i);
		ptr = ptr->next;
	}
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
		print_anthill(anthill);
	}
    return (0);
}
