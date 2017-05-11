/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:31:45 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/11 14:30:27 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "op.h"
# include "corewar.h"

typedef struct s_map	t_map;
typedef int				t_cmd;
typedef struct s_player	t_player;
typedef struct s_decode t_decode;

/*
** nb_player is a number of player in game
** *str is value of corewar (size MEM_SIZE + 1)
** *player is occupation of map with player (size MEM_SIZE + 1)
** player[0] = 1 -> occuped by J1; player[233] = 0 -> free
*/

struct 			s_decode
{
	unsigned char param1;
	unsigned char param2;
	unsigned char param3;
	unsigned char param4;
}				t_decode;

struct			s_map
{
	unsigned		nb_player;
	unsigned char	*str;
	unsigned char	*player;
	size_t			nb_cycles;
	size_t			nb_process;
};

struct			s_player
{
	t_header		header;
	unsigned char	cursor;
	char			*str;
	int 			cycles_cd;
	t_player		*next;
	t_player		*prev;
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
