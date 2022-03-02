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

typedef struct s_danthill
{
	char	*name;
	int		coor[2];
    void	*ptr[MAX_ANTHILL];
}					t_danthill;

#endif
