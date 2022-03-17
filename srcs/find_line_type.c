#include "../includes/lem_in.h"

static void is_command(char *line,t_danthill **anthill, int *er)
{
	if (!ft_strncmp(line, "##", 2))
	{
		//ft_putendl("is_command");
		*er = 0;
	}
}

static void is_com(char *line,t_danthill **anthill, int *er)
{
	if (*line == '#' && !*er)
	{
		//ft_putendl("is_com");
		*er = 1;
	}
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
			while (*str)
			{
				if (ft_isdigit(*str))
					str++;
				else
					return(0);
			}
			return(1);
		}
		else
			return(0);
	}
	return(0);
}

static void	is_room(char *line,t_danthill **anthill, int *er)
{
	int pos;

	pos = 0;
	pos = ft_strchr(line, ' ');
	if (pos)
	{
		is_name(line, pos);
		ft_putendl("is_name");
		if (is_coor(line + pos))
		{
				ft_putendl("is_room");
				*er = 3;
		}

	}
}

static void is_pipe(char *line,t_danthill **anthill, int *er)
{
	return ;
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
	while (i < LINE_TEST)
	{
		g_tab[i].f(line, anthill, &er);
		i++;
	}
	ft_putstr("-->typeof line=");
	ft_putnbr(er);
	ft_putstr("-->line=");
	ft_putstr(line);
	ft_putchar('\n');


	return(1);
}
