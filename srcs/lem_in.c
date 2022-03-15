#include "../includes/lem_in.h"


void parser_lexer(char *buf, t_danthill **anthill, int lock[2])
{
	int 		lock_commande;
	int 		lock_com;
	t_danthill 	*start;
	t_danthill 	*end;


	start = NULL;
	end = NULL;
	lock_commande = 0;
	lock_com = 0;
	find_line_type(buf, anthill);
}

int main(int ac, char **av)
{
	t_danthill	*anthill;
	char 		*buf;
	int			ant_nb;
	int			lock[2];

	lock[0] = 0;
	lock[1] = 0;
	lock[2] = '\n';
	ant_nb = 0;
	anthill = NULL;

	//parser_files() #function to create le
	while ((get_next_line(0, &buf)) > 0)
	{
		if (!ant_nb && !ft_isalnum(ft_atoi(buf)))
			ant_nb = ft_atoi(buf);
		else
		{
			ft_putendl("ant number not provided");
			return(-1);
		}
		parser_lexer(buf, &anthill, lock);
	}
    return 0;
}

/* lock system  type of line  buf =
	->  ## -> trigger a lock for ##
	-> # -> trigger a lock for #
	-> info -> use previous trigger

*/
