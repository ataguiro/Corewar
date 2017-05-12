/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_runtime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:36:18 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/11 16:36:20 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


// void 	vm_call_instruct(t_player *player)
// {
// 	//effectue l' instruction en fonction de l' index

// }

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

void 	vm_load_cycles(t_player *play)
{
	//charge le nb de cycles necessaire pour l'instruction
	//du joueur play dans player->cycles_cd

	play->cycles_cd = g_env.cycles_size[g_env.map.str[play->cursor]];
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
			// vm_call_instruct(play);
			// vm_move_cursor(play);
			vm_load_cycles(play);
		}

	}
}

void 	vm_runtime()
{
	vm_init_player_cycles();
	while (true)
	{
		++g_env.map.nb_cycles;
		vm_do_actions();
		// vm_check_conditions()
	}
}