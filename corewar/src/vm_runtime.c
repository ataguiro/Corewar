/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_runtime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:36:18 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/14 21:02:23 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void 	l_init_cycle_size()
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

static void 	l_init_instructions()
{
	g_env.instruction[0] = NULL;
	g_env.instruction[1] = &in_live;
	g_env.instruction[2] = &in_ld;
	g_env.instruction[3] = &vm_st;
	g_env.instruction[4] = &vm_add;
	g_env.instruction[5] = &vm_subb;
	g_env.instruction[6] = &vm_and;
	g_env.instruction[7] = &vm_or;
	g_env.instruction[8] = &vm_xor;
	g_env.instruction[9] = &vm_zjmp;
	g_env.instruction[10] = &vm_ldi;
	g_env.instruction[11] = &vm_sti;
	g_env.instruction[12] = &vm_fork;
	g_env.instruction[13] = &vm_lld;
	g_env.instruction[14] = &vm_lldi;
	g_env.instruction[15] = &vm_lfork;
	g_env.instruction[16] = &vm_aff;
}

void 	vm_load_cycles(t_player *play)
{
	//charge le nb de cycles necessaire pour l'instruction
	//du joueur play dans player->cycles_cd
	play->cycles_cd = g_env.cycles_size[g_env.map.str[play->pc]];
}

void 	vm_init_player_cycles()
{
	t_player *play;

	play = g_env.player;
	l_init_cycle_size();
	while (play)
	{
		vm_load_cycles(play);
		play = play->next;
	}
}

void 	vm_do_actions()
{
	t_player *play;

	play = g_env.player;
	while (play)
	{
		--play->cycles_cd;
		if (!play->cycles_cd)
		{
			db_show_map();
			vm_call_instruct(play);
			vm_load_cycles(play);
		}
		play = play->next;
	}
}

void 	vm_runtime()
{
	vm_init_player_cycles();
 	l_init_instructions();
	while (true)
	{
		++g_env.map.nb_cycles;
		vm_do_actions();
		vm_check_conditions();
		// getchar();
	}
}
