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

# define MAX_ROOM 100000
# define ER_LINE 42
# define ER_ANT_NOT_GIVEN 84

# define LINE_TEST 4
# define START 1
# define END 2



typedef struct s_room
{
	int					ant;
	char				*name;
	int					cor[2];
	struct s_room		*next;
	struct s_room		*prev;
}					t_room;

typedef struct	s_piperoom
{
	struct s_room		*room;
	struct s_piperoom 	*next;
}				t_piperoom;

typedef struct s_danthill
{
	int					lock_start_end;
	size_t				ant_nb;
	struct s_piperoom	*hash_table[MAX_ROOM];
	struct s_room		*start;
	struct s_room		*end;
	struct s_room		*head;
	struct s_room		*tail;
}					t_danthill;

typedef struct		s_tab
{
	int				i;
	t_room		*(*f)(char *, int *er, int *start_end);
}					t_tab;

void 			init_anthill(t_danthill **anthill, int ant_nb);
void 			save_room(t_room *new_node, t_danthill **anthill);
void			pipe_creation(char *line, t_danthill **anthill);

int				find_line_type(char *line, t_danthill **anthill);

t_room 		*create_room(char *line, int *start_end, int pos);


t_danthill 		*er_in_map(int code, t_danthill **anthill);


int				ft_natoi(const char *str, size_t cn);
int				hash(char *item);

void 			edk_algo(t_danthill *anthill);


#endif
