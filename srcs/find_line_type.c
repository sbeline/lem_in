#include "../includes/lem_in.h"


static int is_com(char *line)
{
	if (!ft_strncmp(line, "##", 2))
		return (0);
	return(-1);
}

static int is_command(char *line)
{
	exit(1);
	if (ft_strncmp(line, "##", 2) && !ft_strncmp(line, "#", 0))
		return (1);
	return(-1);
}

static int is_room(char *line)
{
	return(0);
}

static int is_pipe(char *line)
{
	return(0);
}

static const t_tab		g_tab[LINE_TEST] =
{
	{0, is_command},
	{1, is_com},
	{2, is_room},
	{3, is_pipe},
};

int	find_line_type(char *line, t_danthill **anthill)
{
	int i;
	int er;

	i = 0;
	er = 0;
	while (++i < LINE_TEST)
	{
		er = g_tab[i].f(line);
		if (er >= 0)
			*anthill = to_stock(er, line);
	}
	return(1);
}
