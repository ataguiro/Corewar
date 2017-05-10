/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:31:45 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/10 20:58:17 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "op.h"

typedef struct s_map	t_map;
typedef int				t_cmd;
typedef struct s_player	t_player;

/*
** nb_player is a number of player in game
** *str is value of corewar (size MEM_SIZE + 1)
** *player is occupation of map with player (size MEM_SIZE + 1)
** player[0] = 1 -> occuped by J1; player[233] = 0 -> free
*/

struct			s_map
{
	unsigned		nb_player;
	char			*str;
	unsigned char	*player;
};

struct			s_player
{
	t_header	header;
	char		*str;
	t_player	*next;
	t_player	*prev;
};

typedef struct	s_vm_env
{
	t_map			map;
	t_player		*player;
	t_cmd			cmd;
	unsigned char	opt;
}				t_vm_env;

t_vm_env		g_env;

#endif
