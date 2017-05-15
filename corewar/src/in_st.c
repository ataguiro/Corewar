/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:21 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/15 19:32:10 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void vm_st(t_player *player)
{
	t_decode *args;
	size_t curs;
	
	curs = (player->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++]);
	vm_get_arg(args, &curs);
	if (args->param2 == 1 && args->arg2 < 17)
		player->reg[args->arg2] = player->reg[args->arg1];
	else if (args->param2 == 2)
		vm_replace_int(player->pc + (args->arg2 % IDX_MOD), player->reg[args->arg1]);

	/*
		si arg2 == registre ET arg2 < 17 -> copier reg[arg1] dans reg[arg2]
		si arg2 == indirect -> PC + (arg2 % IDX_MOD) == reg[arg1]
	*/

	if (args->param2 == 1 && args->arg2 < 17)
		player->reg[args->arg2] = player->reg[args->arg1];
	else if (args->param2 == 2)
		player->pc = (player->pc + (args->arg2 % IDX_MOD)) % MEM_SIZE;
	player->pc = curs % MEM_SIZE;
}
