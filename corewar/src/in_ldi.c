/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:22 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/18 10:35:07 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	in_ldi(t_player *player)
{
	t_decode *args;
	size_t	curs;

	curs = (player->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++]);
	args->param1 == 4 ? args->param1 = 2 : 0;
	args->param2 == 4 ? args->param2 = 2 : 0;
	vm_get_arg(args, &curs);
	args->arg1 = (short)args->arg1;
	args->arg2 = (short)args->arg2;
	if (args->param1 == 1 && args->arg1 > 0 && args->arg1 < 17)
		args->arg1 = player->reg[args->arg1];
	else if ((g_env.map.str[(player->pc + 1) % MEM_SIZE] & 0xC0) == 0xC0)
		args->arg1 = vm_get_param_val(
				(player->pc + (args->arg1 % IDX_MOD)) % MEM_SIZE, 4);
	if (args->param2 == 1 && args->arg2 > 0 && args->arg2 < 17)
		args->arg2 = player->reg[args->arg2];
	if (args->param1 && args->param2 && args->param3)
	{
		if (args->arg3 > 0 && args->arg3 < 17)
			player->reg[args->arg3] = vm_get_param_val(player->pc +
				((args->arg1 + args->arg2) % IDX_MOD) % MEM_SIZE, 4);
		player->pc = curs % MEM_SIZE;
	}
	else
		player->pc = (player->pc + 2) % MEM_SIZE;
	db_show_reg(player);
}
