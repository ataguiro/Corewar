/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:38 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/18 13:47:19 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void in_fork(t_player *player)
{
	size_t		curs;
	int			value;

	curs = (player->pc + 1) % MEM_SIZE;
	value = (short)vm_get_param_val(curs, 2) % IDX_MOD;
	vm_lst_add_cpy(&player);
	player->pc = (player->pc + 3) % MEM_SIZE;
	g_env.player->pc = (g_env.player->pc + value) % MEM_SIZE;
	g_env.player->instr = g_env.map.str[g_env.player->pc];
	g_env.map.nb_process++;
	if (g_env.player->instr > 0 && g_env.player->instr < 17)
		g_env.player->cycles_cd = g_env.cycles_size[g_env.player->instr];
	else
		g_env.player->cycles_cd = 1;
}