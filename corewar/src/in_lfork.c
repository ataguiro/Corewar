/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:37:08 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/18 13:48:17 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void in_lfork(t_player *player)
{
	size_t		curs;
	int			value;

	curs = (player->pc + 1) % MEM_SIZE;
	value = (short)vm_get_param_val(curs, 2);
	vm_lst_add_cpy(&player);
	player->pc = (player->pc + 3) % MEM_SIZE;
	player->prev->pc = (player->prev->pc + value) % MEM_SIZE;
	player->prev->instr = g_env.map.str[player->prev->pc];
	if (player->prev->instr > 0 && player->prev->instr < 17)
		player->prev->cycles_cd = g_env.cycles_size[player->prev->instr];
	else
		player->prev->cycles_cd = 1;
}