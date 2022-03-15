#include "../includes/lem_in.h"

static int stock_command(char *line, t_danthill **comp)
{
	return(0);
}

static int stock_com(char *line, t_danthill **comp)
{
	return(0);
}

static int stock_room(char *line, t_danthill **comp)
{
	return(0);
}

static int stock_pipe(char *line, t_danthill **comp)
{
	return(0);
}

static const t_stock	g_stock[LINE_TEST] =
{
	{0, stock_com},
	{1, stock_command},
	{2, stock_room},
	{3, stock_pipe},
};

t_danthill *to_stock(int er, char *line)
{
	t_danthill *component;

	component = NULL;
	/* code */
	component = (t_danthill *)ft_memalloc(sizeof(t_danthill));
	component->next = NULL;
	component->prev = NULL;
	g_stock[er].f(line, &component);

	return (component);
}
