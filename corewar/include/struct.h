/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:31:45 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/28 18:03:48 by folkowic         ###   ########.fr       */
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
typedef struct timeval		t_timeval;
typedef struct winsize		t_winsize;
typedef struct s_blink		t_blink;
typedef struct s_win		t_win;
typedef struct s_vm_env		t_vm_env;

enum {PAUSED, RUNING};

/*
** param recupere la taille en octect
*/

struct				s_decode
{
	int				arg1;
	int				arg2;
	int				arg3;
	int				arg4;
	unsigned char	param1;
	unsigned char	param2;
	unsigned char	param3;
	unsigned char	param4;
};

struct				s_map
{
	size_t			nb_cycles;
	size_t			nb_process;
	size_t			nb_live;
	unsigned		nb_player;
	int				cycle_to_die;
	int				*player;
	unsigned char	*str;
	int				*cursor;
};

struct				s_process
{
	t_process		*next;
	t_process		*prev;
	size_t			pc;
	int				player;
	int				reg[REG_NUMBER + 1];
	unsigned int	cycles_cd;
	unsigned char	carry;
	unsigned char	instr;
	bool			is_live;
};

struct				s_player
{
	t_player		*next;
	t_player		*prev;
	t_header		header;
	int				number;
	int				last_live;
	int				total_live;
	char			*str;
};

struct				s_blink
{
	t_blink			*next;
	t_blink			*prev;
	size_t			cd;
	size_t			pos;
};

struct				s_win
{
	t_timeval		clk_new;
	t_timeval		clk_old;
	WINDOW			*w_main;
	WINDOW			*w_mgame;
	WINDOW			*w_game;
	WINDOW			*w_info;
	WINDOW			*b_main;
	WINDOW			*b_game;
	WINDOW			*b_info;
	size_t			rts;
	int				state;
	int				cycl_p_min;
	int				key;
	bool			step;
	bool			increase;
};

struct				s_vm_env
{
	t_win			win;
	t_map			map;
	t_process		*process;
	t_player		*player;
	t_blink			*blink_live;
	t_blink			*blink_st;
	void			(*instruction[17])(t_process *);
	size_t			idx;
	size_t			from;
	char			name_last[PROG_NAME_LENGTH + 1];
	int				number_last;
	int				cmd;
	unsigned int	dump_cycle;
	int				option_nb_play;
	unsigned int	cycles_size[17];
	int				num_player[5];
};

t_vm_env		g_env;

#endif
