/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/07/09 16:24:29 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define  LEM_IN_H

# include "../libft/Includes/libft.h"

# define MAX_ANTHILL 100000
# define ER_LINE 42
# define ER_ANT_NOT_GIVEN 84

#define LINE_TEST 4



typedef struct s_danthill
{
	int					ant;
	char				*name;
	int					coor[2];
    struct s_danthill	*ptr[MAX_ANTHILL];
	struct s_danthill	*next;
	struct s_danthill	*prev;
}					t_danthill;

typedef struct		s_tab
{
	int				i;
	void			(*f)(char *, t_danthill **, int *er);
}					t_tab;


typedef struct		s_stock
{
	int				count;
	int				(*f)(char *, t_danthill **);
}					t_stock;

int				find_line_type(char *line, t_danthill **anthill);
t_danthill		*to_stock(int er, char *line);

#endif
