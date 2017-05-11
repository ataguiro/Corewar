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


void 	vm_call_instruct(t_player *player)
{
	//effectue l' instruction en fonction de l' index
	ptr_tab[g_env.map.str[player->cursor]]();

	t_decode dec;

	dec = vm_decode_octet(g_env.map.str[player->cursor]);

}

void 	vm_load_moves()
{
	//charge le nb de cycles necessaire pour les
	//instructions de chaque joueurs

}

void 	vm_do_actions()
{
	t_player *cur_ply;

	cur_ply = g_env.player;
	while (cur_ply)
	{
		if (!cur_ply->cycles_cd)
		{
			vm_call_instruct(cur_ply);
		}

	}
}

void 	vm_runtime()
{
	g_env.
	vm_load_moves()
	while (true)
	{
		++g_env.map.nb_cycles;
		vm_do_action()
		vm_check_conditions()
	}
}