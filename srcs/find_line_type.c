#include "../includes/lem_in.h"

static t_anthill *is_command(char *line, int *er, int *start_end)
{
	if (!ft_strncmp(line, "##", 2))
	{
		if (ft_strcmp(line + 2,"start"))
			*start_end = START;
		if (ft_strcmp(line + 2,"end"))
			*start_end = END;
		*er = 1;
	}
	return NULL;
}

static t_anthill *is_com(char *line, int *er, int *start_end)
{
	if (*line == '#' && !*er)
	{
		*er = 2;
	}
	return NULL;
}



static int	is_name(char *str, int pos)
{
	int i;

	i = 0;
	if (*str != 'L' && *str != '#')
		return (-1);
	while (i < pos)
	{
		if (!ft_isalnum(str[i]) && !ft_isalpha(str[i]))
			return (-1);
		i++;
	}
	return (2);
}

static int	is_coor(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else if (*str == ' ')
		{
			str++;
			while (*str != '\0' && *str != '\r')
			{
				if (!ft_isdigit(*str))
					return(0);
				else
					str++;
			}
			return(1);
		}
		else
			return(0);
	}
	return(0);
}

static t_anthill	*is_room(char *line, int *er, int *start_end)
{
	int pos;

	pos = 0;
	pos = ft_strchr(line, ' ');
	if (pos)
	{
		is_name(line, pos);
		if (is_coor(line + pos))
		{
			*er = 3;
			return(create_room(line, start_end, pos));

		}
	}
	return NULL;

}

static t_anthill *is_pipe(char *line, int *er, int *start_end)
{
	int pos;

	pos = 0;
	pos = ft_strchr(line, '-');
	if (pos)
	{
		*er = 4;
	}
	return NULL;
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
	int start_end;
	int er;
	t_anthill *new_node;

	new_node = NULL;
	i = 0;
	er = 0;
	start_end = -1;
	while (i < LINE_TEST)
	{
		new_node = g_tab[i].f(line, &er, &start_end);
		if (new_node)
			save_room(new_node, anthill);
		i++;
		ft_putstr(line);
	}

	//Debug tools lexer

	ft_putstr("-->typeof line=");
	ft_putnbr(er);
	ft_putstr("-->line=");
	ft_putstr(line);
	ft_putchar('\n');

	return(1);
}
