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

# define LINE_TEST 4
# define START 1
# define END 2



typedef struct s_anthill
{
	int					ant;
	char				*name;
	int					cor[2];
    struct s_anthill	*ptr[MAX_ANTHILL];
	struct s_anthill	*next;
	struct s_anthill	*prev;
}					t_anthill;

typedef struct s_danthill
{
	size_t				lenght;
	struct s_anthill	*head;
	struct s_anthill	*tail;
}					t_danthill;

typedef struct		s_tab
{
	int				i;
	t_anthill		*(*f)(char *, int *er, int *start_end);
}					t_tab;


int				find_line_type(char *line, t_danthill **anthill);

t_anthill 		*stock_room(char *line, int *start_end, int pos);

#endif
