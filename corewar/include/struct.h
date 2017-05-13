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

typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_decode		t_decode;

/*
** nb_player is a number of player in game
** *str is value of corewar (size MEM_SIZE + 1)
** *player is occupation of map with player (size MEM_SIZE + 1)
** player[0] = 1 -> occuped by J1; player[233] = 0 -> free
*/


//enum des registre pour acceder au tableau. R1=0, R2=1,..R16=15
enum {R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15, R16};

struct 			s_decode
{
	unsigned char param1;
	unsigned char param2;
	unsigned char param3;
	unsigned char param4;
};

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
	int 			number; //numero du joueur
	unsigned int 	nb_live; //nb de live effectuer pendant le Cycle_to_die
	size_t			pc;
	unsigned int 	reg[REG_NUMBER]; //tableau des registre
	unsigned char 	carry;
	unsigned int	cycles_cd; //cool down des cycles. a zero, l'instruction est effectuee
	char			*str;
	t_player		*next;
	t_player		*prev;
};

/*
** player_end is a last link of list
*/

typedef struct	s_vm_env
{
	t_map			map;
	t_player		*player;
	t_player		*player_end;
	int 			cmd;
	unsigned int 	dump_cycle; //pour l' option -dump
	unsigned int 	option_nb_play; // pour l' option -n
	unsigned int 	cycles_size[17];
	void 			(*instruction[17])(t_player *);
}				t_vm_env;

t_vm_env		g_env;

#endif
