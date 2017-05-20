/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_runtime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:36:18 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/18 14:26:52 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		l_init_cycle_size(void)
{
	g_env.cycles_size[0] = 0;
	g_env.cycles_size[1] = 10;
	g_env.cycles_size[2] = 5;
	g_env.cycles_size[3] = 5;
	g_env.cycles_size[4] = 10;
	g_env.cycles_size[5] = 10;
	g_env.cycles_size[6] = 6;
	g_env.cycles_size[7] = 6;
	g_env.cycles_size[8] = 6;
	g_env.cycles_size[9] = 20;
	g_env.cycles_size[10] = 25;
	g_env.cycles_size[11] = 25;
	g_env.cycles_size[12] = 800;
	g_env.cycles_size[13] = 10;
	g_env.cycles_size[14] = 50;
	g_env.cycles_size[15] = 1000;
	g_env.cycles_size[16] = 2;
}

static void		l_init_instructions(void)
{
	g_env.instruction[0] = NULL;
	g_env.instruction[1] = &in_live;
	g_env.instruction[2] = &in_ld;
	g_env.instruction[3] = &in_st;
	g_env.instruction[4] = &in_add;
	g_env.instruction[5] = &in_sub;
	g_env.instruction[6] = &in_and;
	g_env.instruction[7] = &in_or;
	g_env.instruction[8] = &in_xor;
	g_env.instruction[9] = &in_zjmp;
	g_env.instruction[10] = &in_ldi;
	g_env.instruction[11] = &in_sti;
	g_env.instruction[12] = &in_fork;
	g_env.instruction[13] = &in_lld;
	g_env.instruction[14] = &in_lldi;
	g_env.instruction[15] = &in_lfork;
	g_env.instruction[16] = &in_aff;
}

static void		l_init_player_cycles(void)
{
	t_player *play;

	play = g_env.player;
	l_init_cycle_size();
	while (play)
	{
		play->instr = g_env.map.str[play->pc];
		play->cycles_cd = g_env.cycles_size[g_env.map.str[play->pc]];
		play = play->next;
	}
}

static void		l_do_actions(void)
{
	t_player *play;

	play = g_env.player;
	while (play)
	{
		--play->cycles_cd;
		if (!play->cycles_cd)
		{
			vm_call_instruct(play);
			if (g_env.map.str[play->pc] > 0 && g_env.map.str[play->pc] < 17)
			{
				play->cycles_cd = g_env.cycles_size[g_env.map.str[play->pc]];
				play->instr = g_env.map.str[play->pc];
			}
			else
				play->cycles_cd++;
		}
		play = play->next;
	}
}

void 	vm_runtime(void)
{
	l_init_player_cycles();
 	l_init_instructions();
 	g_env.map.cycle_to_die = CYCLE_TO_DIE;
	while (true)
	{
		++g_env.map.nb_cycles;
		l_do_actions();
		if (!(g_env.map.nb_cycles % CYCLE_TO_DIE))
			vm_check_conditions();
		if (!(g_env.cmd & DUMP))
			db_show_map();
		if (g_env.cmd & DUMP && g_env.dump_cycle == g_env.map.nb_cycles)
		{
			db_show_map();
			g_env.cmd ^= DUMP;
			// exit(0);
		}
	}
}