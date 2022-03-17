#include "../includes/lem_in.h"


void parser_lexer(char *buf, t_danthill **anthill)
{
	t_danthill 	*start;
	t_danthill 	*end;


	start = NULL;
	end = NULL;

	find_line_type(buf, anthill);

}

int main(int ac, char **av)
{
	t_danthill	*anthill;
	char 		*buf;
	int			ant_nb;
	int			line_nb;

	line_nb = 0;
	ant_nb = 0;
	anthill = NULL;
	//parser_files() #function to create le
	while ((get_next_line(0, &buf)) > 0)
	{
		if (!ant_nb && !ft_isalnum(ft_atoi(buf)))
			ant_nb = ft_atoi(buf);
		else if (!ant_nb && line_nb > 0)
		{
			ft_putendl("ant number not provided");
			return(-1);
		}
		parser_lexer(buf, &anthill);
		line_nb++;
	}
    return 0;
}
