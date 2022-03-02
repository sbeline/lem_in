#include "../includes/lem_in.h"


int main(int ac, char **av)
{
	char 	*buf;
	int		ant_nb;

	ant_nb = 0;
	if (ac > 1) {
		/* determine argurmnet to commande lem_in */
	}

	//parser_files() #function to create le
	while ((get_next_line(0, &buf)) > 0)
	{
		if (!ant_nb && ft_isalnum(ft_atoi(buf)))
			ant_nb = ft_atoi(buf);
		else
			ft_puterror("ant number not provided");
		ft_putendl(buf);
	}
	ft_putnbr(ant_nb);
    return 0;
}
