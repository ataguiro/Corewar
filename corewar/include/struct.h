/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:31:45 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/20 22:11:34 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "op.h"
# include "corewar.h"

typedef struct s_map		t_map;
typedef struct s_process	t_process;
typedef struct s_player		t_player;
typedef struct s_decode		t_decode;

/*
** nb_player is a number of player in game
** *str is value in corewar (size MEM_SIZE + 1)
** *player is occupation of map with player (size MEM_SIZE + 1)
** player[0] = 1 -> occuped by J1; player[233] = 0 -> free
*/


//enum des registre pour acceder au tableau. R1=0, R2=1,..R16=15
enum {R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15,
	R16};

/*
** param recupere la taille en octect
*/

struct			s_decode
{
	unsigned char	param1;
	unsigned char	param2;
	unsigned char	param3;
	unsigned char	param4;
	int				arg1;
	int				arg2;
	int				arg3;
	int				arg4;
};

struct			s_map
{
	unsigned		nb_player;
	unsigned char	*str;
	int				*player;
	size_t			nb_cycles;
	size_t			nb_process;
	int				cycle_to_die;
};

struct			s_process
{
	unsigned int	nb_live; //nb de live effectuer pendant le Cycle_to_die
	size_t			pc;
	int				reg[REG_NUMBER + 1]; //tableau des registre
	unsigned char	carry;
	unsigned char	instr; //instruction recuperer a l'apparition du curseur
	unsigned int	cycles_cd; //cool down des cycles. a zero, l'instruction est effectuee
	t_process		*next;
	t_process		*prev;
};

struct			s_player
{
	t_header		header;
	int				number; //numero du joueur
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
	t_process		*process;
	t_process		*process_end;
	t_player		*player;
	char			name_last[PROG_NAME_LENGTH + 1];
	int				number_last;
	int				cmd;
	unsigned int	dump_cycle; //pour l' option -dump
	int				option_nb_play; // pour l' option -n
	unsigned int	cycles_size[17];
	void			(*instruction[17])(t_process *);
	int				num_player[5];
	size_t			idx; //utiliser pour la visu
}				t_vm_env;

t_vm_env		g_env;

#endif
